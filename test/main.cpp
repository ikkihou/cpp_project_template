#include "header_file.h"
#include <gtest/gtest.h>
using namespace std;

// Demonstrate some basic assertions.
TEST(unit_test, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}
