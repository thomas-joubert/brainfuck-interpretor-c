#ifndef DEF_INTERPRETOR
#define DEF_INTERPRETOR

#include <stdio.h>
#include <err.h>

#define TOKEN_NUMBER 8

int is_character_valid(const int character);

int lexer(FILE *code, int *cursor);

#endif // end of DEF_INTERPRETOR
