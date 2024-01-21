#include "Mylib.hpp"
#include <cstdlib>

int MyLib::foo() noexcept {
  int n = rand();

  if (n > 0) {
    return 1;
  } else {
    return 2;
  }
}

int MyLib::goo() noexcept {
  int *a = new int();

  delete a;
  // Will trigger address sanitizer failure
  *a = 5;
  return *a;
}