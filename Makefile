# src/main.c src/run_shell.c src/execute_command.c src/run_process.c src/power.c src/fclean.c src/pclean.c src/ecomode.c
# 형 이거 src/*.c 이렇게 하면 안됨. *을 정규 표현식이 아니라 문자로 인식해.

CC = gcc
CFLAGS = -Wall -Iinclude
SRC = src/main.c src/run_shell.c src/execute_command.c src/run_process.c src/power.c src/fclean.c src/pclean.c src/ecomode.c
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
