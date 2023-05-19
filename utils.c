#include "push_swap.h"

int		get_pos(int a[], int i[], int l, int r, int v)
{
	int	m;

	while (r - l > 1)
	{
		m = l + (r - l) / 2;
		if (a[i[m]] <= v)
			r = m;
		else
			l = m;
	}

    return (r);
}

t_byte	*calc_mvs(t_array *arr, t_array *lis)
{
	t_byte	*moves;
	t_array	pos;
	int		i;
	
	moves = (t_byte *)malloc(arr->size * sizeof(t_byte));
	moves = ft_memset(moves, PB, arr->size);
	i = 0;
	while (i < lis->size)
		moves[arr->size - lis->items[i++] - 1] = RA;
	pos.size = arr->size - lis->size;
	pos.items = (int *)ft_calloc(pos.size, sizeof(int));
	i = 0;
	while (i < pos.size)
	{
		if (moves[i] == PB)
			pos.items[i] = get_pos(arr->items, lis->items, -1, lis->size - 1, arr->items[i]);
		i++;
	}
	i = 0;
	while (i < arr->size)
	{
		print_move(moves[i]);
		i++;
	}
	i = 0;
	while (i < pos.size)
	{
		printf("[%d] = %d -> %d\n", i, pos.items[i], arr->items[pos.items[i]]);
		i++;
	}
	
	return (moves);
}