#include "../include/arena.h"
#include "../include/int32array.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  MemoryArena arena;
  arena_init(&arena, 1024 * 1024); // 1 MB arena

  // Test allocations
  int *int_array = (int *)arena_alloc(&arena, 10 * sizeof(int));
  for (int i = 0; i < 10; i++) {
    int_array[i] = i;
  }

  double *double_array = (double *)arena_alloc(&arena, 5 * sizeof(double));
  for (int i = 0; i < 5; i++) {
    double_array[i] = i * 1.0;
  }

  // Print results
  printf("Int array: ");
  for (int i = 0; i < 10; i++) {
    printf("%d ", int_array[i]);
  }
  printf("\n");

  printf("Double array: ");
  for (int i = 0; i < 5; i++) {
    printf("%.2f ", double_array[i]);
  }
  printf("\n");

  // Reset and reuse the arena
  arena_reset(&arena);
  char *str = (char *)arena_alloc(&arena, 50);
  snprintf(str, 50, "Hello, Memory Arena!");
  printf("String: %s\n", str);

  int32_t *value = (int32_t *)arena_alloc(&arena, sizeof(int32_t));
  Int32Array *int_struct_array = Int32Array_create(&arena, 10);

  printf("Int32Array size: %ld\n", sizeof(int_struct_array));
  printf("Array length before: %d\n", int_struct_array->length);

  for (int i = 0; i < int_struct_array->capacity; i++) {
    Int32Array_push(int_struct_array, i * 2);
  }

  printf("Array length after: %d\n", int_struct_array->length);
  printf("Array capacity: %d\n", int_struct_array->length);

  for (int i = 0; i < int_struct_array->length; i++) {
    printf("%d ", Int32Array_get(int_struct_array, i));
  }
  printf("\n");

  Int32Array_iterate(int_struct_array);
  printf("\n");

  if (!value) {
    perror("Allocation failed");
  }

  for (int i = int_struct_array->length; i > 0; i--) {
    Int32Array_pop(int_struct_array, value);
    printf("%d ", *value);
  }
  printf("\n");
  printf("Array length after: %d\n", int_struct_array->length);

  // Clean up
  arena_free(&arena);
  return 0;
}
