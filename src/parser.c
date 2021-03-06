#include "parser.h"
#include "evaluate.h"

static void free_list(struct exp *head)
{
    if (head->next == NULL)
        return;

    free_list(head->next);
    free (head->next);
}

static struct exp *parse_loop(FILE *code, int *cursor)
{
    int saved = *cursor;

    struct exp *main = calloc(1, sizeof(struct exp));
    struct exp *pointer = main;

    enum token curr = 0;

    int first = 1;

    while ((curr = lexer(code, cursor)) != EOF_TOK && curr != LOOP_END)
    {
        if (first)
        {
            main->type = curr;
            first = 0;
            continue;
        }

        struct exp *next = calloc(1, sizeof(struct exp));
        next->type = curr;

        pointer->next = next;
        pointer = next;

        if (curr == LOOP_START)
        {
            pointer->next = parse_loop(code, cursor);
            while (pointer->next)
                pointer = pointer->next;
        }
    }

    if (curr == EOF_TOK)
        errx (4, "Synatx error: Non clausing loop, starts at character %d", saved);

    struct exp *next = calloc(1, sizeof(struct exp));
    next->type = curr;

    pointer->next = next;
    pointer = next;

    return main;
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
            next_expression.next = parse_loop(code, &cursor);

        next_expression.type = curr;

        evaluate(next_expression);

        if (curr == LOOP_START)
        {
            free_list(next_expression.next);
            free(next_expression.next);
        }
    }
}
