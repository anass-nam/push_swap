#include "push_swap.h"

void	print_stack(int *stack, int size)
{
	int i;

	i = -1;
	while (++i <= size)
		printf("%d ", stack[i]);
	printf("\n");
}

static int	sort_checker(int *items, int top) // check if sorted in ascending order
{
	int i;

	i = -1;
	while (++i < top)
		if (items[i] < items[i + 1])
			return (i + 1);
	return (0);
}

static char *decide(int *a, int *b, int at, int bt, int max)
{
	// print_stack(a, at);
	// print_stack(b, bt);	
	if (at > 0 && bt > 0)
	{
		if (a[at] > a[0] && b[bt] < b[0])
			return (RR);
		else if (a[at] > a[at - 1] && b[bt] < b[bt - 1])
			return (SS);
	}
	if (at >= max / 2 && sort_checker(a, at))
	{
		if (a[at] > a[at - 1] && a[at] < a[0])
			return (SA);
		else if (a[at] < a[0] && a[at] < a[at - 1] && a[at] <= max / 2)
			return (PB);
		else if (a[at] > a[0] && a[at] > max / 2)
			return (RA);
	}
	else if (bt >= 0)
	{
		if (b[bt] < b[bt - 1] && b[bt] > b[0])
			return (SA);
		else if (!bt || b[bt] > b[0])
			return (PA);
		else if (bt > 0 && b[bt] < b[0])
			return (RB);
	}
	return (NULL);
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
	while (sort_checker(a->items, a->top) || b->top > -1)
		call(decide(a->items, b->items, a->top, b->top, a->max), &a, &b);
	print_stack(a->items, ac - 2);
	return 0;
}



