#ifndef DOUBLE_ARRAY_H
#define DOUBLE_ARRAY_H

#include "../include/arena.h"
#include <stddef.h>
#include <stdint.h>

typedef struct DoubleArray {
  double *items;
  size_t length;
  size_t capacity;
} DoubleArray;

DoubleArray *DoubleArray_create(MemoryArena *arena, size_t capacity);
double DoubleArray_get(DoubleArray *array, size_t index);
void DoubleArray_iterate(DoubleArray *array);
size_t DoubleArray_push(DoubleArray *array, double value);
size_t DoubleArray_pop(DoubleArray *array, double *value);

#endif // DOUBLE_ARRAY_H