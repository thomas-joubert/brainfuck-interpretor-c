#include "interpretor.h"

char memory[30000] = { 0 };

char available_tokens[8] = {
    '>',
    '<',
    '+',
    '-',
    '.',
    ',',
    '[',
    ']'
};

int lexer(FILE *code, int *cursor)
{
    if (fseek(code, (*cursor)++, SEEK_SET) == -1)
        err(3, "Error reading code");

    int character = fgetc(code);
    if (is_character_valid(character))
        return character;

    errx(4, "Unrecognized token \'%c\' at character %d", (char)character, *cursor);
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
