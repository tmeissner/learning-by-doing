#include <stdint.h>
#include <string.h>
#include <stdbool.h>



void LedDriver_Create(uint16_t *address);
void LedDriver_Destroy(uint16_t *address);
void LedDriver_TurnOn(int ledNumber);
void LedDriver_TurnOff(int ledNumber);
void LedDriver_TurnAllOn(void);
void LedDriver_TurnAllOff(void);
bool LedDriver_IsOn(int ledNumber);
bool LedDriver_IsOff(int ledNumber);
