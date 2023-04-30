#include "push_swap.h"

static void print_stack(t_stack *s)
{
	int i;

	i = 0;
	while (i <= s->top)
	{
		ft_putnbr_fd(s->items[i], STDOUT_FILENO);
		ft_putchar_fd(' ', STDOUT_FILENO);
		i++;
	}
	ft_putchar_fd('\n', STDOUT_FILENO);
}

static void	ps_init(t_ps *stack, int count, char const **args)
{
	stack->a->items = parse_args(count, args);
	if (stack->a->items == NULL)
	{
		ft_putendl_fd(ERR, STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
	stack->a->top = count - 1;
	stack->b->items = (int *)malloc(count * sizeof(int));
	if (stack->b->items == NULL)
	{
		free(stack->a->items);
		ft_putendl_fd(ERR, STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
	stack->b->top = -1;
}

static void	sort_stack(t_ps *stack)
{
	t_byte	*lis_moves;
	int i;
	int l;

	lis_moves = calculate(stack->a->items, stack->a->top + 1);
	i = 0;
	l = stack->a->top + 1;
	while (i < l)
	{
		call(stack, lis_moves[i]);
		print_stack(stack->a);
		print_stack(stack->b);
		i++;
	}
}

int main(int ac, char const **av)
{
	t_ps	stack;
	t_stack	a;
	t_stack	b;

	stack.a = &a;
	stack.b = &b;
	ps_init(&stack, ac - 1, av + 1);
	print_stack(stack.a);
	sort_stack(&stack);
	print_stack(stack.a);
	print_stack(stack.b);
	return 0;
}
