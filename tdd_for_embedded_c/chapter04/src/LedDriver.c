#include "LedDriver.h"
#include "../util/RuntimeError.h"



enum {ALL_LEDS_ON = ~0x0000, ALL_LEDS_OFF = ~ALL_LEDS_ON};
enum {FIRST_LED = 1, LAST_LED = 16};

static uint16_t *ledsAddress = NULL;  // LEDs memory register location
static uint16_t ledsImage;            // internal variable to store LEDs state


static uint16_t convertLedNumberToBit(int ledNumber) {
  return 1 << (ledNumber - 1);
}


static bool IsLedOutOfBound(int ledNumber) {
  return (ledNumber < 1) || (ledNumber > 16);
}


static void SetLedImageBit(int ledNumber) {
  ledsImage |= convertLedNumberToBit(ledNumber);
}


static void ClearLedImageBit(int ledNumber) {
  ledsImage &= ~(convertLedNumberToBit(ledNumber));
}


static void updateHardware(void) {
  if(ledsAddress == NULL) {
    RUNTIME_ERROR("LED Driver: NULL pointer access", -1);
    return;
  }
  *ledsAddress = ledsImage;
}


void LedDriver_Create(uint16_t *address) {
  if(address == NULL) {
    RUNTIME_ERROR("LED Driver: NULL pointer access", -1);
    return;
  }
  ledsAddress = address;
  ledsImage = ALL_LEDS_OFF;
  updateHardware();
}


void LedDriver_Destroy(void) {
}


void LedDriver_TurnOn(int ledNumber) {
  if (IsLedOutOfBound(ledNumber)) {
    RUNTIME_ERROR("LED Driver: out-of-bounds LED", -1);
    return;
  }

  SetLedImageBit(ledNumber);
  updateHardware();
}


void LedDriver_TurnAllOn(void) {
  ledsImage = ALL_LEDS_ON;
  updateHardware();
}


void LedDriver_TurnOff(int ledNumber) {
  if (IsLedOutOfBound(ledNumber)) {
    RUNTIME_ERROR("LED Driver: out-of-bounds LED", -1);
    return;
  }

  ClearLedImageBit(ledNumber);
  updateHardware();
}


void LedDriver_TurnAllOff(void) {
  ledsImage = ALL_LEDS_OFF;
  updateHardware();
}


bool LedDriver_IsOn(int ledNumber) {
  if(IsLedOutOfBound(ledNumber)) {
    return false;
  }
  return ledsImage & 1 << (ledNumber - 1);
}


bool LedDriver_IsOff(int ledNumber) {
  return !(LedDriver_IsOn(ledNumber));
}
