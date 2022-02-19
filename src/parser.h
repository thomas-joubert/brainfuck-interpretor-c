#ifndef DEF_PARSER
#define DEF_PARSER

#include "lexer.h"
#include <stdlib.h>

struct exp
{
    enum token type;
    struct exp *next;
};

void parser(FILE *code);

void evaluate(const struct exp expression);

#endif // end of DEF_PARSER
