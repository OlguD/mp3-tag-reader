CC = gcc
CFLAGS = -Wall -Werror
TARGET = mp3_reader

# Source files
SRCS = read_mp3.c

# Object files
OBJS = $(SRCS:.c=.o)

# Header files
HEADERS = read_mp3.h

# Rule to build the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to build object files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule to remove object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: clean
