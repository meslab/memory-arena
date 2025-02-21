#include "include/test_int_array.h"
#include <stdio.h>

void int_array_print(int *array, size_t size) {
  printf("Int array: ");
  for (size_t i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}
