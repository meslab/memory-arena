#include "../include/test_string.h"
#include <stdio.h>

void test_string_allocation(MemoryArena *arena) {
  char *str = (char *)arena_alloc(arena, 25);
  snprintf(str, 25, "Hello, Memory Arena!");
  printf("String: %s\n", str);
}

void test_string_from(MemoryArena *arena) {
  const String *const string =
      (String *)String_from(arena, "Hi there! I am a String!");
  if (string) {
    printf("%.*s\n", (int)string->length, string->chars);
  }
}

void test_string_slice(MemoryArena *arena) {
  const String *const string =
      (String *)String_from(arena, "Hi there! I am a String!");
  const String *const slice = String_slice(arena, string, 10, 14);
  if (slice) {
    printf("%.*s\n", (int)slice->length, slice->chars);
  }
}

void test_string_unicode_from(MemoryArena *arena, const char *input) {
  const String *const string = (String *)String_from(arena, input);
  if (string) {
    printf("%.*s\n", (int)string->length, string->chars);
  }
}
