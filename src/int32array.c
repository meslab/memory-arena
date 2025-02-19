#include "../include/int32array.h"
#include "../include/arena.h"
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

Int32Array *Int32Array_create(MemoryArena arena, int32_t capacity) {
  Int32Array *int_struct_array =
      (Int32Array *)arena_alloc(&arena, sizeof(Int32Array));

  int_struct_array->capacity = capacity;
  int_struct_array->length = 0;
  int_struct_array->items = (int32_t *)arena_alloc(
      &arena, int_struct_array->capacity * sizeof(int32_t));

  return int_struct_array;
}