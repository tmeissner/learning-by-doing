#include "LedDriver.h"
#include "../util/RuntimeError.h"



enum {ALL_LEDS_ON = ~0x0000, ALL_LEDS_OFF = ~ALL_LEDS_ON};

static uint16_t *ledsAddress = NULL;  // LEDs memory register location
static uint16_t ledsImage;            // internal variable to store LEDs state


static uint16_t convertLedNumberToBit(int ledNumber) {
  return 1 << (ledNumber - 1);
}


static void updateHardware(void) {
  if(ledsAddress == NULL) {
    return;
  }
  *ledsAddress = ledsImage;
}


void LedDriver_Create(uint16_t *address) {
  ledsAddress = address;
  ledsImage = ALL_LEDS_OFF;
  updateHardware();
}


void LedDriver_Destroy(uint16_t *address) {
}


void LedDriver_TurnOn(int ledNumber) {
  if(ledNumber < 0 || ledNumber > 16) {
    RUNTIME_ERROR("LED Driver: out-of-bounds LED", -1);
    return;
  }

  ledsImage |= convertLedNumberToBit(ledNumber);
  updateHardware();
}


void LedDriver_TurnAllOn(void) {
  ledsImage = ALL_LEDS_ON;
  updateHardware();
}


void LedDriver_TurnOff(int ledNumber) {
  if(ledNumber < 0 || ledNumber > 16) {
    RUNTIME_ERROR("LED Driver: out-of-bounds LED", -1);
    return;
  }

  ledsImage &= ~(convertLedNumberToBit(ledNumber));
  updateHardware();
}
