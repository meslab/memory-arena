CC = gcc
CFLAGS = -std=c99 -Wall -Werror -Wextra -Iinclude -O2 -flto -fPIC
LIB_DIR = lib
INCLUDE_DIR = include
LIB_NAME = arena
STATIC_LIB = $(LIB_DIR)/lib$(LIB_NAME).a
SHARED_LIB = $(LIB_DIR)/lib$(LIB_NAME).so
TEST_SRC = test/test_arena.c
TEST_STATIC_BIN = $(LIB_DIR)/test_arena_static
TEST_SHARED_BIN = $(LIB_DIR)/test_arena_shared

# Targets
all: $(STATIC_LIB) $(SHARED_LIB) test_static test_shared

# Build static library
$(STATIC_LIB): src/arena.c
	mkdir -p $(LIB_DIR)
	$(CC) $(CFLAGS) -c src/arena.c -o $(LIB_DIR)/arena.o
	ar rcs $(STATIC_LIB) $(LIB_DIR)/arena.o

# Build shared library
$(SHARED_LIB): src/arena.c
	mkdir -p $(LIB_DIR)
	$(CC) $(CFLAGS) -shared -o $(SHARED_LIB) src/arena.c

# Test with static library
test_static: $(STATIC_LIB) $(TEST_SRC)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $(TEST_SRC) $(STATIC_LIB) -o $(TEST_STATIC_BIN)

# Test with shared library
test_shared: $(SHARED_LIB) $(TEST_SRC)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $(TEST_SRC) -L$(LIB_DIR) -l$(LIB_NAME) -o $(TEST_SHARED_BIN)
	
# Run tests
run_static: test_static
	$(TEST_STATIC_BIN)

run_shared: test_shared
	LD_LIBRARY_PATH=$(LIB_DIR) ./$(TEST_SHARED_BIN)

# Clean build artifacts
clean:
	rm -rf $(LIB_DIR)/*.o $(STATIC_LIB) $(SHARED_LIB) $(TEST_STATIC_BIN) $(TEST_SHARED_BIN)

