#include "parser.h"
#include "evaluate.h"

static void parse_loop(void)
{
    return;
}

void parser(FILE *code)
{
    int cursor = 0;

    struct exp next_expression = { EOF_TOK, NULL };

    enum token curr = 0;
    while ((curr = lexer(code, &cursor)) != EOF_TOK)
    {
       if (curr == LOOP_START)
           parse_loop();
       else
           next_expression.type = curr;

       evaluate(next_expression);
    }
}
