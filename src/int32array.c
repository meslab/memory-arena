#include "../include/int32array.h"
#include <stdio.h>

int Int32Array_get(Int32Array array, int32_t index) {
  if (index >= 0 && index < array.length) {
    return array.items[index];
  }
  return 0;
}
