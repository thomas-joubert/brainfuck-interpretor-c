#ifndef DEF_PARSER
#define DEF_PARSER

#include "lexer.h"

struct exp
{
    enum token type;
    void *data;
};

void parser(FILE *code);

void evaluate(const struct exp expression);

#endif // end of DEF_PARSER
