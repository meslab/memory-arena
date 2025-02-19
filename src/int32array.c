#include "../include/int32array.h"
#include "../include/arena.h"
#include <stdio.h>

int Int32Array_get(Int32Array array, int32_t index) {
  if (index >= 0 && index < array.length) {
    return array.items[index];
  }
  return -1;
}

void Int32Array_iterate(Int32Array array) {
  for (int i = 0; i < array.length; i++) {
    int item = Int32Array_get(array, i);
    printf("%d ", item);
  }
}

Int32Array *Int32Array_create(MemoryArena arena, int32_t capacity) {
  Int32Array *int_struct_array =
      (Int32Array *)arena_alloc(&arena, sizeof(Int32Array));

  int_struct_array->capacity = capacity;
  int_struct_array->length = 0;
  int_struct_array->items =
      (int32_t *)arena_alloc(&arena, capacity * sizeof(int32_t));

  return int_struct_array;
}

int8_t Int32Array_push(Int32Array *array, int32_t value) {
  array->items[array->length] = value;
  if (array->items[array->length] == value) {
    array->length += 1;
    return 1;
  }
  return 0;
}

int8_t Int32Array_pop(Int32Array *array, int32_t *value) {
  if (array->length > 0) {
    *value = array->items[--array->length];
    return 1; // success
  }
  return 0; // failure
}