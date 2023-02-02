#include "push_swap.h"

void	sort_stack(t_stack **stack)
{
	while ((*stack)->a->top && sort_checker())
	{
		/* code */
	}
	
}






int main(int ac, char const *av[])
{
	int *v = get_items((char **)av + 1, ac - 1);
	t_stack *stack;
	if (!v)
		write(2, ERR, 6);
	else
		stack = init_stack(ac - 1, &v);
	return 0;
}
