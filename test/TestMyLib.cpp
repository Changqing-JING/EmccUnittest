#include "../src/MyLib/Mylib.hpp"
#include "gtest/gtest.h"

TEST(TestMyLib, TestFoo) {
  MyLib myLib;

  int const res = myLib.foo();

  ASSERT_NE(res, 0);
}

TEST(TestMyLib, TestGoo) {
  MyLib myLib;

  int const res = myLib.goo();

  ASSERT_NE(res, 0);
}