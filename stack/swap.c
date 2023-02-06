#include "stack.h"

void	swap(t_stack **s)
{
	int		i;
	int		tmp;

	if ((*s)->top <= LESS)
		return ;
	i = (*s)->top;
	tmp = (*s)->items[i];
	(*s)->items[i] = (*s)->items[i - 1];
	(*s)->items[i - 1] = tmp;
}
