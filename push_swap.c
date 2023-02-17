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

// static char *decide(int *a, int *b, int at, int bt, int max)
static char *decide(t_stack *a, t_stack *b)
{
	char	*op;

	print_stack(a->items, a->top);
	print_stack(b->items, b->top);
	op = NULL;
	if (a->max == 3)
	{
		if (a->items[a->top] > a->items[a->top - 1] && a->items[a->top] > a->items[0])
			op = RA;
		else
			op = SA;
		return (op);
	}
	
	if (a->top > 0 && b->top > 0)
	{
		if (a->items[a->top] > a->items[a->top - 1] && a->items[a->top] > a->items[0]
			&& b->items[b->top] < b->items[b->top - 1] && b->items[b->top] < b->items[0])
			return (RR);
		else if (a->items[a->top - 1] > a->items[a->top] && a->items[a->top - 1] > a->items[0]
			&& b->items[b->top - 1] < b->items[b->top] && b->items[b->top - 1] < b->items[0])
			return (SS);
	}
	
	if (a->items[a->top] > a->items[a->top - 1] && a->items[a->top] > a->items[0])
			op = RA;
	else if ((a->items[a->top] < a->max / 2 || (a->items[a->top] < a->items[a->top - 1] && a->items[a->top] < a->items[0])) && sort_checker(a->items, a->top))
		op = PB;
	else if (!sort_checker(a->items, a->top))
		op = PA;
	else
		op = SA;
	
	
	return (op);
}

int main(int ac, char const *av[])
{
	int *items;
	t_stack *a;
	t_stack *b;

	items = parse_items(av + 1, ac - 1);
	a = init_stack(ac - 1, &items);
	b = init_stack(ac - 1, NULL);
	while (sort_checker(a->items, a->top) || b->top > -1)
		call(decide(a, b), &a, &b);
		// call(decide(a->items, b->items, a->top, b->top, a->max), &a, &b);
	print_stack(a->items, ac - 2);
	return 0;
}



/*

1 3 2 ----> a[at] < a[at - 1] && a[at - 1] > a[0]



****************************************************1 mv
3 2 1 ----> a[at] > a[at - 1] && a[at - 1] > a[0]		
3 1 2 ----> a[at] > a[at - 1] && a[at - 1] < a[0]	RA
2 3 1 ----> a[at] < a[at - 1] && a[at - 1] > a[0]	RRA
2 1 3 ----> a[at] < a[at - 1] && a[at - 1] < a[0]	SA

1 2 3 ----> a[at] < a[at - 1] && a[at - 1] < a[0]	--
*/