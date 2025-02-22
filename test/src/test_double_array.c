#include "../../include/arena.h"
#include "../../include/double_array.h"

#include "../include/test_double_array.h"
#include <stdio.h>
#include <stdlib.h>

void test_double_array(MemoryArena *arena, size_t size) {
  DoubleArray *double_array = DoubleArray_create(arena, size);

  print_double_array_status(double_array);

  test_populate_double_array(double_array);

  print_double_array_status(double_array);

  for (int i = 0; i < double_array->length; i++) {
    printf("%d ", DoubleArray_get(double_array, i));
  }
  printf("\n");

  DoubleArray_iterate(double_array);
  printf("\n");

  size_t array_length;
  array_length = DoubleArray_push(double_array, 10);
  printf("An attempt to push beyond the array capacity\n");
  if (!array_length) {
    printf("Passed, return: %ld\n", array_length);
  }

  double *value = (double *)arena_alloc(arena, sizeof(int32_t));
  if (!value) {
    perror("Allocation failed");
  }

  for (int i = double_array->length; i > 0; i--) {
    DoubleArray_pop(double_array, value);
    printf("%.2f ", *value);
  }
  printf("\n");

  array_length = DoubleArray_pop(double_array, value);
  print_double_array_status(double_array);
}

inline void test_populate_double_array(DoubleArray *double_array) {
  for (int i = 0; i < double_array->capacity; i++) {
    DoubleArray_push(double_array, i * 2);
  }
}

inline void print_double_array_status(DoubleArray *double_array) {
  printf("DoubleArray size: %ld\n", sizeof(double_array));
  printf("Array length: %d\n", double_array->length);
  printf("Array capacity: %d\n", double_array->capacity);
}