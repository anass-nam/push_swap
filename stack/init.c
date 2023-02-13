#include "stack.h"

t_stack	*init_stack(int max, int **items) // init the stacks
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		err("Malloc failed");
	stack->max = max;
	stack->top = max - 1;
	if (items && *items)
		stack->items = *items;
	else
	{
		stack->items = (int *)malloc(sizeof(int) * max);
		stack->top = -1;
	}
	if (!stack->items)
		err("Malloc failed");
	return (stack);
}