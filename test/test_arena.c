#include "../include/arena.h"
#include "../include/int32array.h"
#include <stdio.h>
#include <stdlib.h>

void int_array_print(int *array, size_t size) {
  printf("Int array: ");
  for (size_t i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

void double_array_print(double *array, size_t size) {
  printf("Int array: ");
  for (size_t i = 0; i < size; i++) {
    printf("%.2f ", array[i]);
  }
  printf("\n");
}

void test_allocations(MemoryArena *arena, int32_t size) {
  int *int_array = (int *)arena_alloc(arena, size * sizeof(int));
  for (int i = 0; i < size; i++) {
    int_array[i] = i;
  }

  int_array_print(int_array, size);

  double *double_array = (double *)arena_alloc(arena, size * sizeof(double));
  for (int i = 0; i < size; i++) {
    double_array[i] = i * 1.0;
  }

  double_array_print(double_array, size);
}

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

int main() {
  MemoryArena arena;
  arena_init(&arena, 1024 * 1024); // 1 MB arena

  test_allocations(&arena, 10);

  arena_reset(&arena);

  char *str = (char *)arena_alloc(&arena, 50);
  snprintf(str, 50, "Hello, Memory Arena!");
  printf("String: %s\n", str);

  test_int32_array(&arena, 10);

  // Clean up
  arena_free(&arena);
  return 0;
}
