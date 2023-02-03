#include "stack.h"

void	pa(t_stack **s)
{
	if ((*s)->b->top > -1)
	{
		(*s)->a->items[++(*s)->a->top] = (*s)->b->items[(*s)->b->top--];
		printf("%s\n", __FUNCTION__);
	}
}

void	pb(t_stack **s)
{
	if ((*s)->a->top > -1)
	{
		(*s)->b->items[++(*s)->b->top] = (*s)->a->items[(*s)->a->top--];
		printf("%s\n", __FUNCTION__);
	}
}
