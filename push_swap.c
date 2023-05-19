#include "push_swap.h"

static void	init_stack(t_ps *stack, t_array	*arr)
{
	stack->a->items = arr->items;
	stack->a->top = arr->size - 1;
	stack->b->items = (int *)malloc(sizeof(int) * arr->size);
	stack->b->top = -1;
	if (stack->b->items == NULL)
	{
		ft_putendl_fd(ERR, STDOUT_FILENO);
		free(arr->items);
		free(arr);
		exit(EXIT_FAILURE);
	}
}

static t_byte issorted(int *items, int size)
{
	int	i;

	i = 0;
	while (++i < size)
		if (items[i - 1] < items[i])
			return (0);
	return (1);
}

static void	free_mem(t_ps *stack, t_array *arr, t_array *lis)
{
	free(stack->a->items);
	free(stack->b->items);
	free(arr);
	free(lis->items);
	free(lis);
}

static void print_stack(t_ps *stack)
{
	int i;

	i = 0;
	ft_putstr_fd("A >",STDOUT_FILENO);
	while (i <= stack->a->top)
	{
		ft_putchar_fd(' ', STDOUT_FILENO);
		ft_putnbr_fd(stack->a->items[i], STDOUT_FILENO);
		i++;
	}
	ft_putchar_fd('\n', STDOUT_FILENO);
	i = 0;
	ft_putstr_fd("B >",STDOUT_FILENO);
	while (i <= stack->b->top)
	{
		ft_putchar_fd(' ', STDOUT_FILENO);
		ft_putnbr_fd(stack->b->items[i], STDOUT_FILENO);
		i++;
	}
	ft_putchar_fd('\n', STDOUT_FILENO);

}

int main(int ac, char const **av)
{
	t_ps	stack;
	t_stack	a;
	t_stack	b;
	t_array	*arr;
	t_array	*lis;

	if (ac < 2)
		return (1);
	arr = parse_args(ac - 1, av + 1);
	if (arr == NULL)
		return (ft_putendl_fd(ERR, STDOUT_FILENO), 1);
	else if (issorted(arr->items, arr->size))
		return (free(arr->items), free(arr), 0);
	stack.a = &a;
	stack.b = &b;
	init_stack(&stack, arr);
	print_stack(&stack);
	lis = get_lis(arr);
	printf("lis >");
	for (size_t i = 0; i < lis->size; i++)
		printf(" %d", lis->items[i]);
	printf("\n");
	calc_mvs(arr, lis);
	free_mem(&stack, arr, lis);
	return 0;
}



// i should have 2 arrays one for the lis, second for elements pushed to B


// 
