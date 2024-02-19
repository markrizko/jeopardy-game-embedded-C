# Compiler and flags
CC = gcc
CFLAGS = -Wall -Werror
CFLAGS += $(shell pkg-config --cflags json-c)
LDFLAGS += $(shell pkg-config --libs json-c)

# Object files
OBJ_FILES = $(patsubst %.c,%.o,$(SRCS))

# Executable file
EXEC = jeopardy

# Sources and headers
SRCS = qna.c jeopardy.c
HDRS = qna.h

# Dependencies
all: $(EXEC)

$(EXEC): $(OBJ_FILES)
	$(CC) $(CFLAGS)  -o $(EXEC) $(OBJ_FILES) $(LDFLAGS)

%.o: %.c $(HDRS)
	$(CC) $(CFLAGS)  -c $< -o $@ $(LDFLAGS)

# Cleaning up
clean:
	rm -f $(OBJ_FILES) $(EXEC)