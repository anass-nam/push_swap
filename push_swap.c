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

void	sort(t_ps *stack)
{
	int	i;
	int	x;
	int	y;
	int	z;

	i = stack->a->size;
	while (i--)
	{
		call(stack, PB);
		x = *(int *)stack->b->items->content;
		y = *(int *)stack->b->items->next->content;
		z = *(int *)ft_lstlast(stack->b->items)->content;
		if (stack->b->size > 1)
		{
			
		}
	}		
}

int main(int ac, char const **av)
{
	t_ps	stack;
	t_stack	a;
	t_stack	b;

	a.items = parse_args(ac - 1, av + 1);
	a.size = ft_lstsize(a.items);
	b.items = NULL;
	b.size = 0;
	stack.a = &a;
	stack.b = &b;
	sort(&stack);
	
	return 0;
}



// i should have 2 arrays one for the lis, second for elements pushed to B


// 
