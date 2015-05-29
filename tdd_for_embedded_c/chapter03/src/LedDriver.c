#include "LedDriver.h"



static uint16_t *ledsAddress;


void LedDriver_Create(uint16_t *address) {
  ledsAddress = address;
  *ledsAddress = 0x0000;
}


void LedDriver_Destroy(uint16_t *address) {
}


void LedDriver_TurnOn(int ledNumber) {
  *ledsAddress = 0x0001;
}


void LedDriver_TurnOff(int ledNumber) {
  *ledsAddress = 0x0000;
}