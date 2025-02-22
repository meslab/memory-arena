#ifndef TEST_DOUBLE_ARRAY_H
#define TEST_DOUBLE_ARRAY_H

#include <stdlib.h>

void test_double_array(MemoryArena *arena, size_t size);

void test_double_arra_get(DoubleArray *double_array);
void test_double_array_push(DoubleArray *double_array);

void test_populate_double_array(DoubleArray *double_array);
void print_double_array_status(DoubleArray *double_array);

#endif