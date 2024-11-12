# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c99

# Source files
SRCS = main.c kalman_filter.c

# Object files
OBJS = $(SRCS:.c=.o)

# Executable name
EXEC = kalman_filter

# Default target
all: $(EXEC)

# Link object files to create the executable
$(EXEC): $(OBJS)
    $(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

# Compile source files into object files
%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
    rm -f $(OBJS) $(EXEC)

# Run the executable
run: $(EXEC)
    ./$(EXEC)