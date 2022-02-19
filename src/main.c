#include <stdio.h>
#include <err.h>

#include "utils.h"
#include "lexer.h"
#include "parser.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        display_help();
        return 0;
    }

    FILE *code = xfopen(argv[1], "r");

    parser(code);

    fclose(code);

    return 0;
}
