CC=gcc
CFLAGS=-std=c99 -pedantic -Werror -Wall -Wextra

OBJS=src/main.o src/utils.o src/lexer.o
BIN=interpretor

all: $(OBJS)
	$(CC) $(OBJS) -o $(BIN)

check: all
	./tests/testsuite.sh

clean:
	$(RM) $(OBJS) $(BIN)

.PHONY: clean
