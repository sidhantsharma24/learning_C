# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS = -lgmp

# Target executable
TARGET = euclidean

# Source files
SRCS = euclidean.c

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS) $(LDFLAGS)

# Clean build files
clean:
	rm -f $(TARGET) *.o
