#include "lexer.h"

static char available_tokens[8] = {
    '>',
    '<',
    '+',
    '-',
    '.',
    ',',
    '[',
    ']'
};

static enum token map_char(int character)
{
    switch (character)
    {
        case '>':
            return PTR_INC;
        case '<':
            return PTR_DEC;
        case '+':
            return VAL_INC;
        case '-':
            return VAL_DEC;
        case '.':
            return PRINT;
        case ',':
            return GETC;
        case '[':
            return LOOP_START;
        case ']':
            return LOOP_END;
        default :
            return EOF_TOK;
    }

    return EOF_TOK;
}

int is_character_valid(const int character)
{
    for (int i = 0; i < TOKEN_NUMBER; i++)
    {
        if (character == available_tokens[i])
            return 1;
    }

    return 0;
}

enum token lexer(FILE *code, int *cursor)
{
    int character = 0;

    do {
        if (fseek(code, (*cursor)++, SEEK_SET) == -1)
            err(3, "Error reading code");

        character = fgetc(code);
        if (character == EOF)
            return EOF_TOK;

    } while (character == '\n' || character == '\t');

    if (is_character_valid(character))
        return map_char(character);

    errx(4, "Unrecognized token \'%c\' at character %d", (char)character,
            *cursor);
}
