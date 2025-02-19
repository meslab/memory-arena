#ifndef INT32ARRAY_H
#define INT32ARRAY_H

#include "../include/arena.h"
#include <stddef.h>
#include <stdint.h>

typedef struct Int32Array {
  int32_t *items;
  int32_t length;
  int32_t capacity;
} Int32Array;

Int32Array *Int32Array_create(MemoryArena arena, int32_t capacity);
int Int32Array_get(Int32Array array, int32_t index);
void Int32Array_iterate(Int32Array array);
void Int32Array_push(Int32Array *array, int32_t value);
int32_t Int32Array_pop(Int32Array *array);

#endif // INT32ARRAY_H