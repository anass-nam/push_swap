#include "push_swap.h"

static void	push(t_stack *from, t_stack *to)
{
	t_list	*top;

	if (from->size > 0)
	{
		top = from->items;
		from->items = from->items->next;
		from->size--;
		top->next = NULL;
		ft_lstadd_back(&(to->items), top);
		to->size++;
	}
}

static void	rotate(t_stack *stack, t_byte d)
{
	t_list	*top;

	if (stack->size > 1)
	{
		if (d == 1)
		{
			top = stack->items;
			stack->items = stack->items->next;
			top->next = NULL;
			ft_lstadd_back(&stack->items, top);
		}
		else
		{
			top = ft_lstlast(stack->items);
			ft_lstadd_front(&stack->items, top);
			top = ft_lstlast(stack->items);
			top->next = NULL;
		}
	}
}

static void swap(t_stack *stack)
{
	t_list	*new_top;

	if (stack->size > 1)
	{
		new_top = stack->items->next;
		stack->items->next = new_top->next;
		ft_lstadd_front(&stack->items, new_top);
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
