#include "include/test_double_array.h"
#include <stdio.h>

void double_array_print(double *array, size_t size) {
  printf("Int array: ");
  for (size_t i = 0; i < size; i++) {
    printf("%.2f ", array[i]);
  }
  printf("\n");
}
