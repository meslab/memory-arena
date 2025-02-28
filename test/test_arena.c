#include "include/test_arena.h"

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

  test_string_unicode_new(&arena);

  test_string_unicode_from(&arena, "你好");
  test_string_unicode_from(&arena, "مرحبًا");
  test_string_unicode_from(&arena, "سلام");
  test_string_unicode_from(&arena, "Γειά σου");
  test_string_unicode_from(&arena, "здравствуй юникод");
  arena_debug(&arena);

  arena_free(&arena);
  return 0;
}
