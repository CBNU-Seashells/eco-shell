CC = gcc
CFLAGS = -Wall -Iinclude
SRC = src/eco_shell.c src/command.c src/process.c src/power.c src/cleanup.c
OBJ = $(SRC:.c=.o)
TARGET = eco-shell

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
