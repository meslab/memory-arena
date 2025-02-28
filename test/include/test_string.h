#ifndef TEST_STRING_H
#define TEST_STRING_H
#include "../include/arena.h"
#include "../include/string.h"

void test_string_allocation(MemoryArena *arena);

void test_string_new(MemoryArena *arena);
void test_string_unicode_new(MemoryArena *arena);
void test_string_unicode_from(MemoryArena *arena, char * input);
void test_string_slice(MemoryArena *arena);

#endif
