#include <stdio.h>
#include <err.h>

#include "utils.h"
#include "interpretor.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        display_help();
        return 0;
    }

    int cursor = 0;
    FILE *code = xfopen(argv[1], "r");

    char curr = 0;
    while ((curr = lexer(code, &cursor)) != EOF);

    fclose (code);

    return 0;
}