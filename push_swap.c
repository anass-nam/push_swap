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

static void	pll(t_list *list)
{
	while (list)
	{
		ft_putnbr_fd(*(int *)(list->content), STDOUT_FILENO);
		ft_putchar_fd(' ', STDOUT_FILENO);
		list = list->next;
	}
	ft_putchar_fd('\n', STDOUT_FILENO);
}

int main(int ac, char const **av)
{
	t_ps	stack;
	t_stack	a;
	t_stack	b;

	a.items = parse_args(ac - 1, av + 1);
	if (a.items == NULL)
		ft_putendl_fd("Error", STDERR_FILENO);
	pll(a.items);
	stack.sorted = merge_sort(a.items);
	pll(stack.sorted);
	if (stack.sorted == NULL)
		ft_putendl_fd("Error", STDERR_FILENO);
	a.size = ft_lstsize(a.items);
	b.items = NULL;
	b.size = 0;
	stack.a = &a;
	stack.b = &b;
	sort(&stack);
	ft_lstclear(&(a.items), free);
	ft_lstclear(&(stack.sorted), free);

	
	return 0;
}

