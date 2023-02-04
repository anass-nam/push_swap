#include "stack.h"

void	sa(t_stack **s)
{
	int tmp;
	int i;

	i = (*s)->a->top;
	if (i > 0)
	{
		tmp = (*s)->a->items[i];
		(*s)->a->items[i] = (*s)->a->items[i - 1];
		(*s)->a->items[i - 1] = tmp;
		ft_putendl_fd(__FUNCTION__, 1);
	}
}

void	sb(t_stack **s)
{
	int tmp;
	int i;

	i = (*s)->b->top;
	if (i > 0)
	{
		tmp = (*s)->b->items[i];
		(*s)->b->items[i] = (*s)->b->items[i - 1];
		(*s)->b->items[i - 1] = tmp;
		ft_putendl_fd(__FUNCTION__, 1);
	}
}

void	ss(t_stack **s)
{
	sa(s);
	sb(s);
	ft_putendl_fd(__FUNCTION__, 1);
}
