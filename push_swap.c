#include "push_swap.h"

static int	sort_checker(int *items, int top) // check if sorted in ascending order
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
	if (at == 2)
	{
		
	}
	
	return ("");
}

static int	*get_rank(int *arr, int size)
{
	int *rank;
	int i;
	int j;

	rank = (int *)calloc(size, sizeof(int));
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (arr[i] < arr[j])
				rank[i]++;
			j++;
		}
		i++;
	}
	return (rank);
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
	a->rank = get_rank(items, ac - 1);
	b = init_stack(ac - 1, NULL);
	// print_stack(a);
	while (sort_checker(a->items, a->top) || a->max - a->top != 1)
		call(decide(a->items, a->top), &a, &b);
	// print_stack(a);
	return 0;
}

