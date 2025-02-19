#ifndef INT32ARRAY_H
#define INT32ARRAY_H

#include <stddef.h>
#include <stdint.h>

typedef struct {
  int32_t *items;
  int32_t length;
  int32_t capacity;
} Int32Array;

int Int32Array_get(Int32Array array, int32_t index);
void Int32Array_iterate(Int32Array array);
void Int32Array_push(Int32Array *array, int32_t value);

#endif // INT32ARRAY_H