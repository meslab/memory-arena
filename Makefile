CC = gcc
CFLAGS = -Wall -Werror -Wextra -fPIC
CFLAGS_RELEASE = -O2 -flto
CFLAGS_DEBUG = -g
BIN_DIR = bin
LIB_DIR = lib
INCLUDE_DIR = include
LIB_NAME = arena
STATIC_LIB = $(LIB_DIR)/lib$(LIB_NAME).a
SHARED_LIB = $(LIB_DIR)/lib$(LIB_NAME).so

TEST_SRC = $(wildcard test/*.c)
TEST_STATIC_BIN = $(BIN_DIR)/test_arena_static
TEST_SHARED_BIN = $(BIN_DIR)/test_arena_shared

# Gather all source files automatically
SRC_FILES := $(wildcard src/*.c)
OBJ_FILES := $(patsubst src/%.c, $(LIB_DIR)/%.o, $(SRC_FILES))

# Targets
all: $(STATIC_LIB) $(SHARED_LIB) test_static test_shared

# Build static library
$(STATIC_LIB): $(OBJ_FILES)
	mkdir -p $(LIB_DIR) $(BIN_DIR)
	ar rcs $(STATIC_LIB) $(OBJ_FILES)

# Compile each .c file into .o inside the lib directory
$(LIB_DIR)/%.o: src/%.c
	$(CC) $(CFLAGS) $(CFLAGS_RELEASE) -c $< -o $@

# Build shared library
$(SHARED_LIB): $(wildcard src/*.c)
	mkdir -p $(LIB_DIR) $(BIN_DIR)
	$(CC) $(CFLAGS) $(CFLAGS_RELEASE) -shared -o $(SHARED_LIB) $^

# Test with static library
test_static: $(STATIC_LIB) $(TEST_SRC)
	$(CC) $(CFLAGS) $(CFLAGS_RELEASE) -I$(INCLUDE_DIR) $(TEST_SRC) $(STATIC_LIB) -o $(TEST_STATIC_BIN)

# Test with shared library
test_shared: $(SHARED_LIB) $(TEST_SRC)
	$(CC) $(CFLAGS) $(CFLAGS_RELEASE) -I$(INCLUDE_DIR) $(TEST_SRC) -L$(LIB_DIR) -l$(LIB_NAME) -o $(TEST_SHARED_BIN)

# Run tests
run_static: test_static
	$(TEST_STATIC_BIN)

run_shared: test_shared
	LD_LIBRARY_PATH=$(LIB_DIR) ./$(TEST_SHARED_BIN)

test: run_static run_shared

# Clean build artifacts
clean:
	rm -rf $(LIB_DIR)/*

.PHONY: all test_arena_shared test_arena_static test clean run_shared run_static
