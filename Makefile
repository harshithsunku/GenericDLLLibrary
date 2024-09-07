# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -Wshadow -Wformat -Wconversion -Wuninitialized \
         -O0 -march=native -g3 -fsanitize=address -fsanitize=undefined -fsanitize=leak \
         -fstack-protector-strong -D_FORTIFY_SOURCE=2 -Wstrict-aliasing=2 -Wnull-dereference \
         -Wformat-security -fanalyzer -Wcast-align -Wduplicated-cond -Wlogical-op -Wswitch-enum \
         -Wstrict-overflow=2 -Wdouble-promotion -Walloca -fno-omit-frame-pointer -std=c2x \
         -g -ggdb
LDFLAGS = -shared
LIB_NAME = libdll.so

# Source files
SRC = dll.c
OBJ = dll.o
TEST_SRC = lib_test.c
EXEC = lib_test

# Default target
all: $(LIB_NAME) $(EXEC)

# Rule to build the shared library
$(LIB_NAME): $(OBJ)
	$(CC) $(LDFLAGS) $(CFLAGS) $(OBJ) -o $(LIB_NAME)

# Rule to compile the object file
$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -fPIC -c $(SRC) -o $(OBJ)

# Rule to build the test program and link with the shared library
$(EXEC): $(TEST_SRC)
	$(CC) $(CFLAGS) $(TEST_SRC) -L. -ldll -o $(EXEC)

# Clean up the build
clean:
	rm -f $(OBJ) $(LIB_NAME) $(EXEC)

