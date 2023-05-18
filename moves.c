#include "push_swap.h"

static void	push(t_stack *from, t_stack *to)
{
	if (from->top > -1)
		to->items[++to->top] = from->items[from->top--];
}

static void	rotate(t_stack *stack, t_byte d)
{
	int	i;
	int	tmp;

	if (stack->top > 0)
	{
		i = -1;
		if (d == 1)
		{
			tmp = stack->items[stack->top];
			while (++i < stack->top)
				stack->items[stack->top - i] = stack->items[stack->top - i - 1];
			stack->items[0] = tmp;
		}
		else
		{
			tmp = stack->items[0];
			while (++i < stack->top)
				stack->items[i] = stack->items[i + 1];
			stack->items[i] = tmp;
		}
	}
}

static void swap(t_stack *stack)
{
	int top = stack->top;

	if (top > 0)
	{
		stack->items[top] = stack->items[top] ^ stack->items[top - 1];
		stack->items[top - 1] = stack->items[top] ^ stack->items[top - 1];
		stack->items[top] = stack->items[top] ^ stack->items[top - 1];
	}
}

static void	print_move(t_byte move)
{
	if (move == SS)
		ft_putendl_fd("ss", STDOUT_FILENO);
	else if (move == RR)
		ft_putendl_fd("rr", STDOUT_FILENO);
	else if (move == RRR)
		ft_putendl_fd("rrr", STDOUT_FILENO);
	else if (move & SA)
		ft_putendl_fd("sa", STDOUT_FILENO);
	else if (move & SB)
		ft_putendl_fd("sb", STDOUT_FILENO);
	else if (move & RA)
		ft_putendl_fd("ra", STDOUT_FILENO);
	else if (move & RB)
		ft_putendl_fd("rb", STDOUT_FILENO);
	else if (move & RRA)
		ft_putendl_fd("rra", STDOUT_FILENO);
	else if (move & RRB)
		ft_putendl_fd("rrb", STDOUT_FILENO);
	else if (move & PA)
		ft_putendl_fd("pa", STDOUT_FILENO);
	else if (move & PB)
		ft_putendl_fd("pb", STDOUT_FILENO);
}

void	call(t_ps *stack, t_byte move)
{
	if (move & SA)
		swap(stack->a);
	if (move & SB)
		swap(stack->b);
	if (move & RA)
		rotate(stack->a, 1);
	if (move & RB)
		rotate(stack->b, 1);
	if (move & RRA)
		rotate(stack->a, 0);
	if (move & RRB)
		rotate(stack->b, 0);
	if (move & PA)
		push(stack->b, stack->a);
	if (move & PB)
		push(stack->a, stack->b);
	print_move(move);
}
