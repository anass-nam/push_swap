#include "stack.h"

void	rot(t_stack **s)
{
	int		i;
	int		tmp;

	if ((*s)->top <= LESS)
		return ;
	i = (*s)->top;
	tmp = (*s)->items[i];
	while (i > 0)
	{
		(*s)->items[i] = (*s)->items[i - 1];
		i--;
	}
	(*s)->items[0] = tmp;
}
