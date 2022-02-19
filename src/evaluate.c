#include "evaluate.h"
#include "lexer.h"

#define INC_VAL_EVAL memory[cursor]++
#define DEC_VAL_EVAL memory[cursor]--
#define PRINT_EVAL  putchar(memory[cursor])
#define GETC_EVAL memory[cursor] = getchar()

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

void evaluate_loop(struct exp expression)
{
    if (!memory[cursor])
        return;

    struct exp *cur = expression.next;

    while (1)
    {
        if (cur->type == LOOP_END && memory[cursor] == 0)
            break;
        else if (cur->type == LOOP_END)
            cur = expression.next;

        evaluate(*cur);

        cur = cur->next;
    }
}

void evaluate (const struct exp expression) //TODO : use function pointer in struct exp
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
            INC_VAL_EVAL;
            break;
        case VAL_DEC:
            DEC_VAL_EVAL;
            break;
        case PRINT:
            PRINT_EVAL;
            break;
        case GETC:
            GETC_EVAL;
            break;
        case LOOP_END:
            break;
        case LOOP_START:
            evaluate_loop(expression);
            break;
        default:
            return;
    }
}
