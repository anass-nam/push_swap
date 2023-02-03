#include "stack.h"

t_stack	*init_stack(int max, int **items) // init the stacks
{
	t_stack	*stack;
	t_so	*a;
	t_so	*b;

	stack = (t_stack *)malloc(sizeof(t_stack));
	a = (t_so *)malloc(sizeof(t_so));
	b = (t_so *)malloc(sizeof(t_so));
	if (stack && a && b)
	{
		a->items = *items;
		a->max = max;
		a->top = max - 1;
		b->items = (int *)calloc(sizeof(int), max);
		if (b->items)
		{
			b->max = max;
			b->top = EMPTY;
			stack->a = a;
			stack->b = b;
			return (stack);
		}
	}
	return (free(stack), free(a), free(b), (t_stack *)0);
}