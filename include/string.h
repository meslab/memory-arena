#ifndef STRING_H
#define STRING_H

#include "../include/arena.h"
#include <stddef.h>

typedef struct String {
  char *chars;
  size_t length;
} String;

String *String_new(MemoryArena *arena, size_t size);
String *String_from(MemoryArena *arena, const char *chars);
String *String_slice(MemoryArena *arena, const String *string, size_t from,
                     size_t length);

#endif // STRING_H