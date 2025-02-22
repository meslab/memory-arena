#include "../../include/arena.h"
#include "../../include/int32_array.h"

#include <stdio.h>
#include <stdlib.h>

void test_int32_array(MemoryArena *arena, size_t size) {
  Int32Array *int32_array = Int32Array_create(arena, size);

  printf("Int32Array size: %ld\n", sizeof(int32_array));
  printf("Array length before push: %d\n", int32_array->length);

  for (int i = 0; i < int32_array->capacity; i++) {
    Int32Array_push(int32_array, i * 2);
  }

  printf("Array length after push: %d\n", int32_array->length);
  printf("Array capacity: %d\n", int32_array->length);

  for (int i = 0; i < int32_array->length; i++) {
    printf("%d ", Int32Array_get(int32_array, i));
  }
  printf("\n");

  Int32Array_iterate(int32_array);
  printf("\n");

  size_t array_length;
  array_length = Int32Array_push(int32_array, 10);
  printf("An attempt to push beyond the array capacity\narray_length = "
         "%ld\n",
         array_length);

  int32_t *value = (int32_t *)arena_alloc(arena, sizeof(int32_t));
  if (!value) {
    perror("Allocation failed");
  }

  for (int i = int32_array->length; i > 0; i--) {
    Int32Array_pop(int32_array, value);
    printf("%d ", *value);
  }
  printf("\n");

  array_length = Int32Array_pop(int32_array, value);
  printf("An attempt to pop an empty array\narray_length = %ld\n",
         array_length);

  printf("Array length after pop: %d\n", int32_array->length);
}
