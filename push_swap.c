#include "push_swap.h"

static t_byte issorted(int *items, int size)
{
	int	i;

	i = 0;
	while (++i < size)
		if (items[i - 1] < items[i])
			return (0);
	return (1);
}

void	check_dup(t_stack *stack, t_array *lis)
{
	int	*stack_arr;
	int	index;
	int	dup;
	int	i;

	stack_arr = (int *)malloc((stack->size + 1) * sizeof(int));
	index = stack->size;
	dup = -1;
	while (stack)
	{
		stack = stack->items->next;
	}
	


}

int main(int ac, char const **av)
{
	t_ps	stack;
	t_stack	a;
	t_stack	b;
	t_array	lis;

	a.items = parse_args(ac - 1, av + 1);
	a.size = ft_lstsize(a.items);
	b.items = NULL;
	b.size = 0;
	stack.a = &a;
	stack.b = &b;
	stack.lis = &lis;
	check_dup(stack.a, stack.lis);
	
	return 0;
}



// i should have 2 arrays one for the lis, second for elements pushed to B


// 
