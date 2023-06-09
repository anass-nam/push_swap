#include "checker.h"

static t_byte	issorted(t_stack *s)
{
	int	*top;
	int	i;

	top = s->a->items;
	i = 1;
	if (s->b->size == 0)
	{
		while (i < s->a->size && top[i - 1] < top[i])
			i++;
		if (i == s->a->size)
			return (OK);
	}
	return (KO);
}

t_byte	checker_sort(t_stack *s)
{
	t_list	*move;

	move = s->moves;
	while (move)
	{
		call(s, move);
		move = move->next;
	}
	return (issorted(s));
}