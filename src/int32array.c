#include "../include/int32array.h"
#include <stdio.h>

int Int32Array_get(Int32Array array, int32_t index) {
  if (index >= 0 && index < array.length) {
    return array.items[index];
  }
  return 0;
}

void Int32Array_iterate(Int32Array array) {
  for (int i = 0; i < array.length; i++) {
    int item = Int32Array_get(array, i);
    printf("%d ", item);
  }
}

void Int32Array_push(Int32Array *array, int32_t value) {
  array->items[array->length] = value;
  array->length += 1;
}