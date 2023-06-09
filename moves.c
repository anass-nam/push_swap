#include "push_swap.h"

static void	push(t_array *from, t_array *to)
{
	t_list	*top;

	if (from->size > 0)
	{
		ft_memmove(to->items + 1, to->items, sizeof(int) * to->size);
		to->items[0] = from->items[0];
		to->size++;
		from->size--;
		ft_memmove(from->items, from->items + 1, sizeof(int) * from->size);
	}
}

static void	rotate(t_array *stack, t_byte d)
{
	int	top;

	if (stack->size > 1)
	{
		if (d == 1)
		{
			top = stack->items[0];
			ft_memmove(stack->items, stack->items + 1, sizeof(int) * (stack->size - 1));
			stack->items[stack->size - 1] = top;
		}
		else
		{
			top = stack->items[stack->size - 1];
			ft_memmove(stack->items + 1, stack->items, sizeof(int) * (stack->size - 1));
			stack->items[0] = top;
		}
	}
}

static void swap(t_array *stack)
{
	if (stack->size > 1)
	{
		stack->items[0] ^= stack->items[1];		
		stack->items[1] ^= stack->items[0];		
		stack->items[0] ^= stack->items[1];		
	}
}

void	print_move(t_byte move)
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

void	call(t_stack *stack, t_byte move)
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
