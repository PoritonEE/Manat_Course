# Compiler
CC = gcc

# Compiler flags
CFLAGS = -g -Wall -std=c99

# Object files
OBJS = main.o student.o stack.o

# Executable name (with .exe extension for Windows)
EXEC = prog.exe

# Command to remove files
RM = rm -f

# Default target
all: $(EXEC)

# Linking rule
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compilation rules
main.o: main.c student.h stack.h common.h
	$(CC) $(CFLAGS) -c -o $@ $<

student.o: student.c student.h common.h
	$(CC) $(CFLAGS) -c -o $@ $<

stack.o: stack.c stack.h common.h
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean up rule
clean:
	$(RM) $(OBJS) $(EXEC)

# Phony targets
.PHONY: all clean
