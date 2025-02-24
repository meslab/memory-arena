#include "../include/test_string.h"
#include <stdio.h>

void test_string_allocation(MemoryArena *arena) {
  char *str = (char *)arena_alloc(arena, 25);
  snprintf(str, 25, "Hello, Memory Arena!");
  printf("String: %s\n", str);
}

void test_string_new(MemoryArena *arena) {
  String *string = (String *)String_new(arena, "Hi there! I am a String!");
  if (string) {
    printf("%s\n", string->chars);
  }
}

void test_string_slice(MemoryArena *arena) {
  String *string = (String *)String_new(arena, "Hi there! I am a String!");
  String *slice = String_slice(arena, string, 10, 14);
  if (slice) {
    printf("%.*s\n", (int)slice->length, slice->chars);
  }
}