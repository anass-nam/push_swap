#include "push_swap.h"

static int sort_checker(int *items, int top) // check if sorted in ascending order
{
	int i;

	i = -1;
	while (++i < top)
		if (items[i] < items[i + 1])
			return (i + 1);
	return (0);
}

static char *decide(int *a, /*int *b,*/ int at/*, int bt*/) // decide what to do with A and B stacks
{
	if (sort_checker(a, at) > ((at + 1) / 2))
	{
		if (a[0] < a[at])
			return (RRA);
	}
	else if (sort_checker(a + ((at + 1) / 2), at - ((at + 1) / 2)))
	{
		if (a[at] > a[0] && a[at] > a[at - 1])
			return (RA);
		else if (a[at - 1] > a[at] && a[at - 1] > a[0])
			return (SA);
	}
	else
	{
		if (a[at - 1] < a[0] && a[at - 1] < a[at])
			return (SA);
		else if (a[0] < a[at] && a[0] < a[at - 1])
			return (RRA);
		else
			return (RA);
	}
	
	return ("");
}

// print stack
void	print_stack(t_stack *stack)
{
	int i;

	i = -1;
	while (++i <= stack->top)
		printf("%d ", stack->items[i]);
	printf("\n");
}

int main(int ac, char const *av[])
{
	int *items;
	t_stack *a;
	t_stack *b;

	items = parse_items(av + 1, ac - 1);
	a = init_stack(ac - 1, &items);
	b = init_stack(ac - 1, NULL);
	// print_stack(a);
	while (sort_checker(a->items, a->top) || a->max - a->top != 1)
		call(decide(a->items, a->top), &a, &b);
	
	// print_stack(a);

	return 0;
}
