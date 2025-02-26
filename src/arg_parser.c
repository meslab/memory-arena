#include "../include/arg_parser.h"
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

void parse_arguments(int argc, char *argv[], Options *opts) {

  opts->memory_arena_size = 1024 * 1024;
  opts->array_lenght = 10;
  opts->verbose = 0;

  static struct option long_options[] = {
      {"array-length", optional_argument, 0, 'l'},
      {"memory-arena-size", optional_argument, 0, 'm'},
      {"verbose", no_argument, 0, 'v'},
      {"help", no_argument, 0, 'h'},
      {0, 0, 0, 0}};

  int opt;
  while ((opt = getopt_long(argc, argv, "m:l:v", long_options, NULL)) != -1) {
    switch (opt) {
    case 'm':
      if (optarg) {
        opts->memory_arena_size = atoi(optarg) * 1024;
      }
      break;
    case 'l':
      if (optarg) {
        opts->array_lenght = atoi(optarg);
      }
      break;
    case 'v':
      opts->verbose = 1;
      break;
    case 'h':
      printf("Usage: %s [-l value] [-m value] [-v] [--help]\n", argv[0]);
      exit(0);
    default:
      exit(1);
    }
  }
}
