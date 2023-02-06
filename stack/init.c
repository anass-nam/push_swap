#include "stack.h"

t_stack	*init_stack(int max, int **items) // init the stacks
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	if (items)
		stack->items = *items;
	else
		stack->items = (int *)malloc(sizeof(int) * max);
	if (!stack->items)
		return (free(stack), NULL);
	stack->max = max;
	stack->top = max - 1;
	return (stack);
}