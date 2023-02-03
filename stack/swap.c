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
		printf("%s\n", __FUNCTION__);
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
		printf("%s\n", __FUNCTION__);
	}
}

void	ss(t_stack **s)
{
	sa(s);
	sb(s);
	printf("%s\n", __FUNCTION__);
}
