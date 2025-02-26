#include "../include/arena.h"
#include "../include/arg_parser.h"
#include "../include/double_array.h"
#include "../include/int32_array.h"

#include "include/test_double.h"
#include "include/test_double_array.h"
#include "include/test_int.h"
#include "include/test_int32_array.h"
#include "include/test_string.h"

#include <stdio.h>
#include <stdlib.h>

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

int main(int argc, char *argv[]) {
  Options opts;
  parse_arguments(argc, argv, &opts);

  MemoryArena arena;
  arena_init(&arena, opts.memory_arena_size);

  arena_debug(&arena);
  test_allocations(&arena, opts.array_lenght);

  test_string_new(&arena);

  arena_debug(&arena);
  arena_reset(&arena);

  arena_debug(&arena);
  test_string_new(&arena);

  test_string_allocation(&arena);

  test_int32_array(&arena, opts.array_lenght);

  arena_debug(&arena);
  test_double_array(&arena, opts.array_lenght);

  arena_debug(&arena);
  test_string_new(&arena);

  test_string_slice(&arena);

  arena_debug(&arena);

  arena_free(&arena);
  return 0;
}
