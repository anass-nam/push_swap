#include "stack.h"

void	rra(t_stack **s)
{
	int top;
	int	i;
	int tmp;

	top = (*s)->a->top;
	if (top > 0)
	{
		i = -1;
		tmp = (*s)->a->items[0];
		while (++i < top)
			(*s)->a->items[i] = (*s)->a->items[i + 1];
		(*s)->a->items[i] = tmp;
		ft_putendl_fd(__FUNCTION__, 1);
	}
}

void	rrb(t_stack **s)
{
	int top;
	int	i;
	int tmp;

	top = (*s)->b->top;
	if (top > 0)
	{
		i = -1;
		tmp = (*s)->b->items[0];
		while (++i < top)
			(*s)->b->items[i] = (*s)->b->items[i + 1];
		(*s)->b->items[i] = tmp;
		ft_putendl_fd(__FUNCTION__, 1);
	}
}

void	rrr(t_stack **s)
{
	rra(s);
	rrb(s);
	ft_putendl_fd(__FUNCTION__, 1);
}
