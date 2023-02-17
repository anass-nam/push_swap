#include "push_swap.h"

static char *small(int *a, int top)
{
    if (a->items[a->top] > a->items[a->top - 1] && a->items[a->top] > a->items[0])
        return (RA);

    return (SA);
}

char    *decide(t_stack *a, t_stack *b)
{
	char	*op;

	print_stack(a->items, a->top);
	print_stack(b->items, b->top);
	op = NULL;
	
	
	
	return (op);
}