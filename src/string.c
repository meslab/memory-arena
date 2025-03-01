#include "../include/string.h"
#include <string.h>

String *String_new(MemoryArena *arena, size_t size) {
  String *string = (String *)arena_alloc(arena, sizeof(String));
  string->length = size;
  string->chars = arena_alloc(arena, string->length * sizeof(char));

  return string;
}

String *String_from(MemoryArena *arena, const char *chars) {
  String *string = (String *)arena_alloc(arena, sizeof(String));
  string->length = strlen(chars);
  string->chars = arena_alloc(arena, string->length * sizeof(char));

  memcpy(string->chars, chars, string->length);

  return string;
}

String *String_slice(MemoryArena *arena, const String *string, size_t from,
                     size_t length) {
  if (string->length < from + length) {
    return NULL;
  }
  String *slice = (String *)arena_alloc(arena, sizeof(String));
  slice->length = length;
  slice->chars = string->chars + from;
  return slice;
}