CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
LIB_DIR = lib
LIB_NAME = arena
LIB = $(LIB_DIR)/lib$(LIB_NAME).a

# Targets
all: $(LIB) test

$(LIB): src/arena.c
	mkdir -p $(LIB_DIR)
	$(CC) $(CFLAGS) -c src/arena.c -o $(LIB_DIR)/arena.o
	ar rcs $(LIB) $(LIB_DIR)/arena.o

test: $(LIB) test/test_arena.c
	$(CC) $(CFLAGS) test/test_arena.c -L$(LIB_DIR) -l$(LIB_NAME) -o $(LIB_DIR)/test_arena

clean:
	rm -rf $(LIB_DIR)

.PHONY: all clean
