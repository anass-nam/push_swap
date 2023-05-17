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

int		get_pos2(int a[], int l, int r, int v)
{
	int	m;

	while (r - l > 1)
	{
		m = l + (r - l) / 2;
		if (a[m] <= v)
			r = m;
		else
			l = m;
	}

    return (r);
}

t_byte	*calc_first_mvs(t_array *arr, t_array *lis)
{
	t_byte	*moves;
	int		i;

	moves = (t_byte *)malloc(arr->size * sizeof(t_byte));
	moves = ft_memset(moves, PB, arr->size);
	i = 0;
	while (i < lis->size)
		moves[lis->items[i++]] = RA;
	return (moves);
}