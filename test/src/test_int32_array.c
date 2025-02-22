#include "../../include/arena.h"
#include "../../include/int32_array.h"

#include "../include/test_int32_array.h"
#include <stdio.h>
#include <stdlib.h>

void test_int32_array(MemoryArena *arena, size_t size) {

  Int32Array *int32_array = Int32Array_create(arena, size);

  print_int32_array_status(int32_array);

  test_populate_int32_array(int32_array);

  print_int32_array_status(int32_array);

  test_int32_array_get(int32_array);

  test_int32_array_iterate(int32_array);

  test_int32_array_push_overflow(int32_array);

  int32_t *value = (int32_t *)arena_alloc(arena, sizeof(int32_t));
  if (!value) {
    perror("Allocation failed");
  }

  for (int i = int32_array->length; i > 0; i--) {
    Int32Array_pop(int32_array, value);
    printf("%d ", *value);
  }
  printf("\n");

  Int32Array_pop(int32_array, value);
  print_int32_array_status(int32_array);
}

void test_int32_array_iterate(Int32Array *int32_array) {
  Int32Array_iterate(int32_array);
  printf("\n");
}
void test_int32_array_get(Int32Array *int32_array) {
  for (int i = 0; i < int32_array->length; i++) {
    printf("%d ", Int32Array_get(int32_array, i));
  }
  printf("\n");
}

void test_int32_array_push_overflow(Int32Array *int32_array) {
  size_t array_length;
  array_length = Int32Array_push(int32_array, 10);
  printf("An attempt to push beyond the array capacity\n");
  if (!array_length) {
    printf("Passed, return: %ld\n", array_length);
  }
}

inline void test_populate_int32_array(Int32Array *int32_array) {
  for (int i = 0; i < int32_array->capacity; i++) {
    Int32Array_push(int32_array, i * 2);
  }
}

inline void print_int32_array_status(Int32Array *int32_array) {
  printf("Int32Array size: %ld\n", sizeof(int32_array));
  printf("Array length: %d\n", int32_array->length);
  printf("Array capacity: %d\n", int32_array->capacity);
}
