#include "utils.h"
#include <stdio.h>

void	print_int(int *arr, int *rank, int size)
{
	while (size--)
		printf("%d\n", arr[rank[size]]);
}

int		*get_rank(int *arr, int size)
{
	int *rank;
	int i;
	int j;
	int tmp;

	rank = (int *)calloc(size, sizeof(int));
	i = 0;
	while (i < size)
	{
		j = 0;
		tmp = 0;
		while (j < size)
		{
			if (arr[i] < arr[j])
				tmp++;
			j++;
		}
		rank[tmp] = i;
		i++;
	}
	return (rank);
}

int main(int ac, char const **av)
{
	int *items;
	int *rank;

	items = parse_items(av + 1, ac - 1);
	rank = get_rank(items, ac - 1);
	print_int(items, get_rank(items, ac - 1), ac - 1);
	
	return 0;
}

