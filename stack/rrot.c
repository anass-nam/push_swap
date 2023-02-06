#include "stack.h"

void rev_rot(t_stack **s)
{
	int		i;
	int		tmp;

	if ((*s)->top <= LESS)
		return ;
	i = 0;
	tmp = (*s)->items[i];
	while (i < (*s)->top)
	{
		(*s)->items[i] = (*s)->items[i + 1];
		i++;
	}
	(*s)->items[(*s)->top] = tmp;
}