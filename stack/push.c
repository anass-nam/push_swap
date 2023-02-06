#include "stack.h"

void	push(t_stack **src, t_stack **dst)
{
	int	s_top;
	int d_top;

	if ((*src)->top == EMPTY)
		return ;
	s_top = (*src)->top;
	d_top = (*dst)->top;
	(*dst)->items[d_top + 1] = (*src)->items[s_top];
	(*dst)->top++;
	(*src)->top--;
}
