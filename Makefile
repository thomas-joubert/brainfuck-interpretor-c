CC=gcc
CFLAGS=-std=c99 -pedantic -Werror -Wall -Wextra

OBJS=src/main.o src/utils.o src/lexer.o src/evaluate.o src/parser.o
BIN=interpretor
LDFLAGS=

all: $(OBJS)
	$(CC) $(OBJS) -o $(BIN)

debug: CFLAGS+=-g -fsanitize=address
debug: LDFLAGS+=-fsanitize=address
debug: $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(BIN)

check: all
	./tests/testsuite.sh

clean:
	$(RM) $(OBJS) $(BIN)

.PHONY: clean
