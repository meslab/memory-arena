#ifndef ARG_PARSER_H
#define ARG_PARSER_H

#include <stddef.h>
#include <stdint.h>

typedef struct Options {
  size_t array_lenght;
  size_t memory_arena_size;
  uint8_t verbose;
} Options;

void parse_arguments(int argc, char *argv[], Options *opt);

#endif // ARG_PARSER_H
