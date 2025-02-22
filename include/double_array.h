#ifndef DOUBLE_ARRAY_H
#define DOUBLE_ARRAY_H

#include "../include/arena.h"
#include <stddef.h>
#include <stdint.h>

typedef struct DoubleArray {
  double *items;
  int32_t length;
  int32_t capacity;
} DoubleArray;

DoubleArray *DoubleArray_create(MemoryArena *arena, int32_t capacity);
int DoubleArray_get(DoubleArray *array, int32_t index);
void DoubleArray_iterate(DoubleArray *array);
size_t DoubleArray_push(DoubleArray *array, double value);
size_t DoubleArray_pop(DoubleArray *array, double *value);

#endif // DOUBLE_ARRAY_H