#include "unity_fixture.h"
#include "../src/LedDriver.h"


TEST_GROUP(LedDriver);


static uint16_t virtualLeds;


TEST_SETUP(LedDriver) {
  LedDriver_Create(&virtualLeds);
}


TEST_TEAR_DOWN(LedDriver) {
}


TEST(LedDriver, LedsOffAfterCreate) {

  uint16_t virtualLeds = 0xFFFF;
  LedDriver_Create(&virtualLeds);

  TEST_ASSERT_EQUAL_HEX16(0x0000, virtualLeds);

}


TEST(LedDriver, TurnOnLedOne) {

  LedDriver_TurnOn(1);

  TEST_ASSERT_EQUAL_HEX16(0x0001, virtualLeds);

}


TEST(LedDriver, TurnOffLedOne) {

  LedDriver_TurnOn(1);
  LedDriver_TurnOff(1);

  TEST_ASSERT_EQUAL_HEX16(0x0000, virtualLeds);

}