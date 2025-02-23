#include "../include/string.h"
#include <string.h>

String *String_new(MemoryArena *arena, char *chars) {
  String *string = (String *)arena_alloc(arena, sizeof(String));
  string->chars = chars;
  string->length = strlen(chars);

  return string;
}