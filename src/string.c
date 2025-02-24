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

String *String_slice(MemoryArena *arena, String *string, size_t from,
                     size_t length) {
  if (string->length < from + length) {
    return NULL;
  }
  String *slice = (String *)arena_alloc(arena, sizeof(String));
  slice->length = length;
  slice->chars = string->chars + from * sizeof(char);
  return slice;
}