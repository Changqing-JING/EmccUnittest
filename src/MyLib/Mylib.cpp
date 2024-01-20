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