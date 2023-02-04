#include "stack.h"

void	pa(t_stack **s)
{
	if ((*s)->b->top > -1)
	{
		(*s)->a->items[++(*s)->a->top] = (*s)->b->items[(*s)->b->top--];
		ft_putendl_fd(__FUNCTION__, 1);
	}
}

void	pb(t_stack **s)
{
	if ((*s)->a->top > -1)
	{
		(*s)->b->items[++(*s)->b->top] = (*s)->a->items[(*s)->a->top--];
		ft_putendl_fd(__FUNCTION__, 1);
	}
}
