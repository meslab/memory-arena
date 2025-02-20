#include "../include/int32array.h"
#include "../include/arena.h"
#include <stdio.h>

int Int32Array_get(Int32Array *array, int32_t index) {
  if (index >= 0 && index < array->length) {
    return array->items[index];
  }
  return -1;
}

void Int32Array_iterate(Int32Array *array) {
  for (int i = 0; i < array->length; i++) {
    int item = Int32Array_get(array, i);
    printf("%d ", item);
  }
}

Int32Array *Int32Array_create(MemoryArena *arena, int32_t capacity) {
  Int32Array *array = (Int32Array *)arena_alloc(arena, sizeof(Int32Array));
  if (array == NULL) {
    return NULL;
  }
  array->capacity = capacity;
  array->length = 0;
  array->items = (int32_t *)arena_alloc(arena, capacity * sizeof(int32_t));

  return array;
}

size_t Int32Array_push(Int32Array *array, int32_t value) {
  if (!array || array->capacity <= array->length) {
    return 0;
  } // failure
  array->items[array->length++] = value;
  return array->length;
}

size_t Int32Array_pop(Int32Array *array, int32_t *value) {
  if (!array || !value || array->length == 0) {
    return 0;
  } // failure
  *value = array->items[--array->length];
  return array->length;
}