#include "parser.h"
#include "evaluate.h"

static void free_list(struct exp *head)
{
    if (head->next == NULL)
        return;

    free_list(head->next);
    free (head->next);
}

static void parse_loop(FILE *code, int *cursor, struct exp *head)
{
    head->type = LOOP_START;
    int saved = *cursor;

    struct exp *pointer = head;

    enum token curr = 0;
    while ((curr = lexer(code, cursor)) != EOF_TOK && curr != LOOP_END)
    {
        struct exp *next = calloc(1, sizeof(struct exp));
        next->type = curr;

        pointer->next = next;
        pointer = next;

        if (curr == LOOP_START)
            parse_loop(code, cursor, pointer);
    }

    if (curr == EOF_TOK)
        errx (4, "Synatx error: Non clausing loop, starts at character %d", saved);

    struct exp *next = calloc(1, sizeof(struct exp));
    next->type = curr;

    pointer->next = next;
}

void parser(FILE *code)
{
    int cursor = 0;

    struct exp next_expression = { EOF_TOK, NULL };

    enum token curr = 0;
    while ((curr = lexer(code, &cursor)) != EOF_TOK)
    {
        if (curr == LOOP_END)
            errx(4, "Synatx error: Loop end without loop start at character %d",
                    cursor);

        if (curr == LOOP_START)
            parse_loop(code, &cursor, &next_expression);
        else
            next_expression.type = curr;

        evaluate(next_expression);

        if (curr == LOOP_START)
            free_list(next_expression.next);
    }
}
