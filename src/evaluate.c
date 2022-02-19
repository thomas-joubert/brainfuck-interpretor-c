#include "evaluate.h"
#include "lexer.h"

static int cursor = 0;
static char memory[30000] = { 0 };

static void evaluate_ptr_inc()
{
    cursor++;

    if (cursor == 30000)
        cursor = 0;
}

static void evaluate_ptr_dec()
{
    cursor--;

    if (cursor == -1)
        cursor = 29999;
}

void evaluate (struct exp expression) //TODO : use function pointer in struct exp
{
    switch (expression.type)
    {
        case PTR_INC:
            evaluate_ptr_inc();
            break;
        case PTR_DEC:
            evaluate_ptr_dec();
            break;
        case VAL_INC:
            memory[cursor]++;
            break;
        case VAL_DEC:
            memory[cursor]--;
            break;
        case PRINT:
            putchar(memory[cursor]);
            break;
        case GETC:
            memory[cursor] = getchar();
            break;
        case LOOP_END:
            break;
        case LOOP_START:
            break;
        default:
            return;
    }
}
