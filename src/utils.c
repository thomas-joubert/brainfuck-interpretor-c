#include <err.h>
#include <stdio.h>

FILE *xfopen(const char *restrict pathname, const char *mode)
{
    FILE *code = fopen(pathname, mode);
    if (!code)
        err(1, "Error while opening \"%s\"", pathname);

    return code;
}

void display_help(void)
{
    puts("Usage: ./interpretor <file.brainfuck>");
}
