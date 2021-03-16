#include "power.hpp"
int powers(int b, int e) {
  
  if (e < 2) {
    return b;
  } else {
    return b * powers(b, --e);
  }
}
