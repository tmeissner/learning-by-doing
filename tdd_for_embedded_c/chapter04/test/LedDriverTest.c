#include "unity_fixture.h"
#include "../src/LedDriver.h"
#include "../mocks/RuntimeErrorStub.h"



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


TEST(LedDriver, TurnOnMultipleLeds) {

  LedDriver_TurnOn(8);
  LedDriver_TurnOn(9);

  TEST_ASSERT_EQUAL_HEX16(0x0180, virtualLeds);

}


TEST(LedDriver, TurnAllOn) {

  LedDriver_TurnAllOn();

  TEST_ASSERT_EQUAL_HEX16(0xFFFF, virtualLeds);

}


TEST(LedDriver, TurnOffAnyLed) {

  LedDriver_TurnAllOn();
  LedDriver_TurnOff(8);

  TEST_ASSERT_EQUAL_HEX16(0xFF7F, virtualLeds);

}


TEST(LedDriver, LedMemoryIsNotReadable) {

  virtualLeds = 0xFFFF;
  LedDriver_TurnOn(8);

  TEST_ASSERT_EQUAL_HEX16(0x0080, virtualLeds);

}


TEST(LedDriver, UpperAndLowerBounds) {

  LedDriver_TurnOn(1);
  LedDriver_TurnOn(16);

  TEST_ASSERT_EQUAL_HEX16(0x8001, virtualLeds);

}


TEST(LedDriver, OutOfBoundsTurnOnDoesNotHarm) {

  LedDriver_TurnOn(-1);
  LedDriver_TurnOn(0);
  LedDriver_TurnOn(17);
  LedDriver_TurnOn(3141);

  TEST_ASSERT_EQUAL_HEX16(0x0000, virtualLeds);

}

TEST(LedDriver, OutOfBoundsTurnOffDoesNotHarm) {

  LedDriver_TurnAllOn();
  LedDriver_TurnOff(-1);
  LedDriver_TurnOff(0);
  LedDriver_TurnOff(17);
  LedDriver_TurnOff(3141);

  TEST_ASSERT_EQUAL_HEX16(0xFFFF, virtualLeds);

}


TEST(LedDriver, OutOfBoundsProducesRuntimeError) {
  LedDriver_TurnOn(-1);

  TEST_ASSERT_EQUAL_STRING("LED Driver: out-of-bounds LED", RuntimeErrorStub_GetLastError());
  TEST_ASSERT_EQUAL(-1, RuntimeErrorStub_GetLastParameter());
}


IGNORE_TEST(LedDriver, OutOfBoundsToDo) {
  /* TODO: what should we do during runtime? */
}
