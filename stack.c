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
		printf("%s\n", __FUNCTION__);
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
		printf("%s\n", __FUNCTION__);
	}
}
void	ss(t_stack **s)
{
	sa(s);
	sb(s);
	printf("%s\n", __FUNCTION__);
}

void	pa(t_stack **s)
{
	if ((*s)->b->top > -1)
	{
		(*s)->a->items[++(*s)->a->top] = (*s)->b->items[(*s)->b->top--];
		printf("%s\n", __FUNCTION__);
	}
}
void	pb(t_stack **s)
{
	if ((*s)->a->top > -1)
	{
		(*s)->b->items[++(*s)->b->top] = (*s)->a->items[(*s)->a->top--];
		printf("%s\n", __FUNCTION__);
	}
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
		printf("%s\n", __FUNCTION__);
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
		printf("%s\n", __FUNCTION__);
	}
}
void	rr(t_stack **s)
{
	ra(s);
	rb(s);
	printf("%s\n", __FUNCTION__);
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
		tmp = (*s)->a->items[0];
		while (++i < top)
			(*s)->a->items[i] = (*s)->a->items[i + 1];
		(*s)->a->items[i] = tmp;
		printf("%s\n", __FUNCTION__);
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
		tmp = (*s)->b->items[0];
		while (++i < top)
			(*s)->b->items[i] = (*s)->b->items[i + 1];
		(*s)->b->items[i] = tmp;
		printf("%s\n", __FUNCTION__);
	}
}
void	rrr(t_stack **s)
{
	rra(s);
	rrb(s);
	printf("%s\n", __FUNCTION__);
}

