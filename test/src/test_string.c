#include "../include/test_string.h"
#include <stdio.h>

void test_string_allocation(MemoryArena *arena) {
  char *str = (char *)arena_alloc(arena, 25);
  snprintf(str, 25, "Hello, Memory Arena!");
  printf("String: %s\n", str);
}

void test_string_new(MemoryArena *arena) {
  String *string = (String *)String_new(arena, "Hi there! I am a String!");
  printf("%s\n", string->chars);
}