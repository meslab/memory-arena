#ifndef TEST_INT_ARRAY_H
#define TEST_INT_ARRAY_H

#include "../../include/arena.h"

#include <stdlib.h>

void test_int32_array(MemoryArena *arena, size_t size);
void test_int32_array_iterate(Int32Array *int32_array);
void test_int32_array_get(Int32Array *int32_array);
void test_int32_array_push_overflow(Int32Array *int32_array);

void test_populate_int32_array(Int32Array *int32_array);
void print_int32_array_status(Int32Array *int32_array);

#endif