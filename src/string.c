#include "../include/string.h"
#include <string.h>

String *String_new(MemoryArena *arena, char *chars) {
  String *string = (String *)arena_alloc(arena, sizeof(String));
  string->length = strlen(chars);
  string->chars = arena_alloc(arena, string->length * sizeof(char));

  for (size_t i = 0; i < string->length; i++) {
    string->chars[i] = chars[i];
  }

  return string;
}