#include <string.h>
#include "unity.h"
#include "unity_fixture.h"


TEST_GROUP(sprintf);


static char output[100];
static const char *expected;



// This is run before each test
TEST_SETUP(sprintf) {

  memset(output, 0xaa, sizeof(output));
  expected = "";

}


// This id run after each test
TEST_TEAR_DOWN(sprintf) {
}


static void expect(const char *s) {

  expected = s;

}


static void given(int charsWritten) {

  TEST_ASSERT_EQUAL(strlen(expected), charsWritten);
  TEST_ASSERT_EQUAL_STRING(expected, &output[1]);
  TEST_ASSERT_EQUAL_HEX8(0xaa, output[strlen(expected)+2]);
  TEST_ASSERT_EQUAL_HEX8(0xaa, output[0]);

}


TEST(sprintf, NoFormatOperations) {

  expect("hey");
  given(sprintf(&output[1], "%s", expected));

}


TEST(sprintf, InsertString) {

  expect("Hello world\n");
  given(sprintf(&output[1], "Hello %s\n", "world"));

}