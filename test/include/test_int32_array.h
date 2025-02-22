#ifndef TEST_INT_ARRAY_H
#define TEST_INT_ARRAY_H

#include "../../include/arena.h"

#include <stdlib.h>

void test_int32_array(MemoryArena *arena, size_t size);

void test_populate_array(Int32Array *int32_array);
void print_array_status(Int32Array *int32_array);

#endif