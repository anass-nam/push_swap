#include "push_swap.h"

t_stack	*init_stack(int max, int **items) // init the stacks
{
	t_stack	*stack;
	t_so	*a;
	t_so	*b;

	stack = (t_stack *)malloc(sizeof(t_stack));
	a = (t_so *)malloc(sizeof(t_so));
	b = (t_so *)malloc(sizeof(t_so));
	if (stack && a && b)
	{
		a->items = *items;
		a->max = max;
		a->top = max - 1;
		b->items = (int *)calloc(sizeof(int), max);
		if (b->items)
		{
			b->max = max;
			b->top = EMPTY;
			stack->a = a;
			stack->b = b;
			return (stack);
		}
	}
	return (free(stack), free(a), free(b), NULL);
}

void	sa(t_stack **s)
{
	int tmp;
	int i;

	i = (*s)->a->top;
	if (i > 0)
	{
		tmp = (*s)->a->items[i];
		(*s)->a->items[i] = (*s)->a->items[i - 1];
		(*s)->a->items[i - 1] = tmp;
	}
}
void	sb(t_stack **s)
{
	int tmp;
	int i;

	i = (*s)->b->top;
	if (i > 0)
	{
		tmp = (*s)->b->items[i];
		(*s)->b->items[i] = (*s)->b->items[i - 1];
		(*s)->b->items[i - 1] = tmp;
	}
}
void	ss(t_stack **s)
{
	sa(s);
	sb(s);
}

void	pa(t_stack **s)
{
	int	atop;
	int	btop;

	atop = (*s)->a->top;
	btop = (*s)->b->top;
	if (btop > -1)
		(*s)->a->items[++atop] = (*s)->b->items[btop--];
}
void	pb(t_stack **s)
{
	int	atop;
	int	btop;

	atop = (*s)->a->top;
	btop = (*s)->b->top;
	if (atop > -1)
		(*s)->b->items[++btop] = (*s)->a->items[atop--];
}

void	ra(t_stack **s)
{
	int top;
	int tmp;

	top = (*s)->a->top + 1;
	if (top > 0)
	{
		tmp = (*s)->a->items[top];
		while (--top)
			(*s)->a->items[top] = (*s)->a->items[top - 1];
		(*s)->a->items[top] = tmp;
	}
}
void	rb(t_stack **s)
{
	int top;
	int tmp;

	top = (*s)->b->top + 1;
	if (top > 0)
	{
		tmp = (*s)->b->items[top];
		while (--top)
			(*s)->b->items[top] = (*s)->b->items[top - 1];
		(*s)->b->items[top] = tmp;
	}
}
void	rr(t_stack **s)
{
	ra(s);
	rb(s);
}

void	rra(t_stack **s)
{
	int top;
	int	i;
	int tmp;

	top = (*s)->a->top;
	if (top > 0)
	{
		i = -1;
		tmp = (*s)->a->items[i];
		while (++i < top)
			(*s)->a->items[i] = (*s)->a->items[i + 1];
		(*s)->a->items[i] = tmp;
	}
}
void	rrb(t_stack **s)
{
	int top;
	int	i;
	int tmp;

	top = (*s)->b->top;
	if (top > 0)
	{
		i = -1;
		tmp = (*s)->b->items[i];
		while (++i < top)
			(*s)->b->items[i] = (*s)->b->items[i + 1];
		(*s)->b->items[i] = tmp;
	}
}
void	rrr(t_stack **s)
{
	rra(s);
	rrb(s);
}

