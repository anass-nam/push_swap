#include "push_swap.h"

static t_byte issorted(t_list *items)
{
	while (items->next)
	{
		if (*(int *)items->content > *(int *)items->next->content)
			return (0);
		items = items->next;
	}
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

static t_byte	rightmove(int item, int bit)
{
	if (item >> bit & 1)
		return (RA);
	return (PB);
}

static void	ps_sort(t_ps *stack, int bit)
{
	int	i;

	if (!issorted(stack->a->items) && bit < (int)sizeof(int) - 1)
	{
		i = stack->a->size;
		while (i--)
		{
			call(stack, rightmove(*(int *)(stack->a->items->content), bit));
			// pll(stack->a->items);
			// pll(stack->b->items);
			// if (stack->b->size > 1)
			// {
			// 	if (*(int *)(stack->a->items->content) > *(int *)(stack->a->items->next->content)
			// 		&& *(int *)(stack->b->items->content) < *(int *)(stack->b->items->next->content))
			// 		call(stack, SS);
			// 	if (*(int *)(stack->b->items->content) < *(int *)(stack->b->items->next->content))
			// 		call(stack, SB);
			// 	// pll(stack->a->items);
			// 	// pll(stack->b->items);
			// }
		}
		i = stack->b->size;
		while (i--)
		{
			call(stack, PA);
			// pll(stack->a->items);
			// pll(stack->b->items);
		}
		ps_sort(stack, bit + 1);
	}
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
	// stack.sorted = merge_sort(a.items);
	// pll(stack.sorted);
	// if (stack.sorted == NULL)
	// 	ft_putendl_fd("Error", STDERR_FILENO);
	a.size = ft_lstsize(a.items);
	b.items = NULL;
	b.size = 0;
	stack.a = &a;
	stack.b = &b;
	ps_sort(&stack, 0);
	pll(a.items);
	ft_lstclear(&(a.items), free);
	// ft_lstclear(&(stack.sorted), free);

	
	return 0;
}

