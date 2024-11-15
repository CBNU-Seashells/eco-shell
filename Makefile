CC = gcc
CFLAGS = -Wall -Iinclude
SRC = src/main.c src/run_shell.c src/command.c src/run_process.c src/power.c src/fclean.c src/pclean.c src/ecomode.c
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
