CC=gcc
CFLAGS=-std=c99 -pedantic -Werror -Wall -Wextra

OBJS=src/main.o src/utils.o src/interpretor.o
BIN=interpretor

all: $(OBJS)
	$(CC) $(OBJS) -o $(BIN)

check:
	./tests/testsuite.sh

clean:
	$(RM) $(OBJS) $(BIN)

.PHONY: clean
