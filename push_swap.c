#include "push_swap.h"

static int sort_checker(int *items, int top) // check if sorted in ascending order
{
	int i;
	int f;

	i = 0;
	f = 1;
	while (i < top)
	{
		if (items[i] > items[i + 1])
		{
			f = 0;
			break ;
		}
		i++;
	}
	return (f);
}

void	qsort(int *items, int size)
{
	
}


// print stack
void	print_stack(t_stack *stack)
{
	int i;

	i = 0;
	while (i <= stack->a->top)
	{
		printf("%d ", stack->a->items[i]);
		i++;
	}
	printf(" | ");
	i = 0;
	while (i <= stack->b->top)
	{
		printf("%d ", stack->b->items[i]);
		i++;
	}
	printf(" | ");
}



int main(int ac, char const *av[])
{
	int *v = get_items((char **)av + 1, ac - 1);
	t_stack *stack;
	stack = NULL;
	if (!v)
		ft_putendl_fd(ERR, 2);
	else
		stack = init_stack(ac - 1, &v);
	if (stack)
	{
		sort_stack(&stack);
		print_stack(stack);
		free(stack->a->items);
		free(stack->b->items);
		free(stack->a);
		free(stack->b);
		free(stack);
	}
	return 0;
}
