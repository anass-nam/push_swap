#include "push_swap.h"

void	print_stack(int *stack, int size)
{
	int i;

	i = -1;
	while (++i <= size)
		printf("%d ", stack[i]);
	printf("\n");
}

// static int	sort_checker(int *items, int top) // check if sorted in ascending order
// {
// 	int i;

// 	i = -1;
// 	while (++i < top)
// 		if (items[i] < items[i + 1])
// 			return (i + 1);
// 	return (0);
// }

// static char *decide(int *a, int *b, int at, int bt, int max)


int main(int ac, char const *av[])
{
	int *items;
	t_stack *a;
	t_stack *b;

	items = parse_items(av + 1, ac - 1);
	a = init_stack(ac - 1, &items);
	b = init_stack(ac - 1, NULL);
	while (a->top >= a->max / 2)
		call(decide(a, b), &a, &b);
		// call(decide(a->items, b->items, a->top, b->top, a->max), &a, &b);
	print_stack(a->items, a->top);
	print_stack(b->items, b->top);
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