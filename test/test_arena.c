#include "../include/arena.h"
#include <stdio.h>

typedef struct {
  int32_t *items;
  int32_t length;
  int32_t capacity;
} Int32Array;

int Int32Array_get(Int32Array array, int32_t index) {
  if (index >= 0 && index < array.length) {
    return array.items[index];
  }
  return 0;
}

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

  Int32Array *int_struct_array =
      (Int32Array *)arena_alloc(&arena, 12 * sizeof(Int32Array));

  int_struct_array->capacity = 10;
  int_struct_array->length = 0;
  int_struct_array->items = (int32_t *)arena_alloc(
      &arena, int_struct_array->capacity * sizeof(int32_t));

  printf("%ld\n", sizeof(int_struct_array));

  for (int i = 0; i < int_struct_array->capacity;) {
    int_struct_array->items[i] = i * 2;
    int_struct_array->length = ++i;
  }

  printf("%d\n", int_struct_array->length);

  for (int i = 0; i < int_struct_array->length; i++) {
    printf("%d ", Int32Array_get(*int_struct_array, i));
  }
  printf("\n");

  // Clean up
  arena_free(&arena);
  return 0;
}
