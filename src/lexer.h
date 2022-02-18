#ifndef DEF_INTERPRETOR
#define DEF_INTERPRETOR

#include <stdio.h>
#include <err.h>

#define TOKEN_NUMBER 8

enum token
{
    PTR_INC = 0,     // >
    PTR_DEC,         // <
    VAL_INC,         // +
    VAL_DEC,         // -
    PRINT,           // .
    GETC,            // ,
    LOOP_START,      // [
    LOOP_END,        // ]
    EOF_TOK          // EOF
};

int is_character_valid(const int character);

enum token lexer(FILE *code, int *cursor);

#endif // end of DEF_INTERPRETOR
