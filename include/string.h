#ifndef STRING_H
#define STRING_H

#include "../include/arena.h"
#include <stddef.h>

typedef struct String {
  char *chars;
  size_t length;
} String;

String *String_new(MemoryArena *arena, char *chars);

#endif // STRING_H