#include "stack.h"

void	ra(t_stack **s)
{
	int top;
	int tmp;

	top = (*s)->a->top + 1;
	if (top > 0)
	{
		tmp = (*s)->a->items[top];
		while (--top)
			(*s)->a->items[top] = (*s)->a->items[top - 1];
		(*s)->a->items[top] = tmp;
		printf("%s\n", __FUNCTION__);
	}
}

void	rb(t_stack **s)
{
	int top;
	int tmp;

	top = (*s)->b->top + 1;
	if (top > 0)
	{
		tmp = (*s)->b->items[top];
		while (--top)
			(*s)->b->items[top] = (*s)->b->items[top - 1];
		(*s)->b->items[top] = tmp;
		printf("%s\n", __FUNCTION__);
	}
}

void	rr(t_stack **s)
{
	ra(s);
	rb(s);
	printf("%s\n", __FUNCTION__);
}
