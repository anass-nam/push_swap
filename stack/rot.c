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
		ft_putendl_fd(__FUNCTION__, 1);
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
		ft_putendl_fd(__FUNCTION__, 1);
	}
}

void	rr(t_stack **s)
{
	ra(s);
	rb(s);
	ft_putendl_fd(__FUNCTION__, 1);
}
