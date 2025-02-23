#include "../include/double_array.h"
#include "../include/arena.h"
#include <stdio.h>

double DoubleArray_get(DoubleArray *array, int32_t index) {
  if (index >= 0 && index < array->length) {
    return array->items[index];
  }
  return -1;
}

void DoubleArray_iterate(DoubleArray *array) {
  for (int i = 0; i < array->length; i++) {
    double item = DoubleArray_get(array, i);
    printf("%.2f ", item);
  }
}

DoubleArray *DoubleArray_create(MemoryArena *arena, int32_t capacity) {
  DoubleArray *array = (DoubleArray *)arena_alloc(arena, sizeof(DoubleArray));
  if (array == NULL) {
    return NULL;
  }
  array->capacity = capacity;
  array->length = 0;
  array->items = (double *)arena_alloc(arena, capacity * sizeof(int32_t));

  return array;
}

size_t DoubleArray_push(DoubleArray *array, double value) {
  if (!array || array->capacity <= array->length) {
    return 0;
  } // failure
  array->items[array->length++] = value;
  return array->length;
}

size_t DoubleArray_pop(DoubleArray *array, double *value) {
  if (!array || !value || array->length == 0) {
    return 0;
  } // failure
  *value = array->items[--array->length];
  return array->length;
}