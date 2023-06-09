#include "push_swap.h"

static void	merge(int *arr, int llen, int rlen)
{
	int	left[llen];
	int	right[rlen];
	int	i;
	int	j;
	int	k;

	i = -1;
	while (++i < llen)
		left[i] = arr[i];
	i = -1;
	while (++i < rlen)
		right[i] = arr[i + llen];
	i = 0;
	j = 0;
	k = 0;
	while (k < llen + rlen)
	{
		if (i < llen && (j >= rlen || left[i] < right[j]))
			arr[k] = left[i++];
		else
			arr[k] = right[j++];
		k++;
	}
}

static void	merge_sort(int *arr, int l, int r)
{
	int	m;

	if (l < r)
	{
		m = l + (r - l) / 2;
		merge_sort(arr, l, m);
		merge_sort(arr, m + 1, r);
		merge(arr + l, m - l + 1, r - m);
	}
}

static int	get_pos(int *arr, int l, int r, int val)
{
	int	m;

	m = (l + (r - l) / 2);
	if (arr[m] != val)
	{
		if (arr[m] < val)
			l = m + 1;
		else
			r = m - 1;
		return (get_pos(arr, l, r, val));
	}
	return (m);
}

t_array	*minimize_range(t_array *arr)
{
	int	*arrcpy;
	int	i;

	if (arr == NULL)
		return (NULL);
	arrcpy = (int *)malloc(arr->size * sizeof (int));
	if (arrcpy == NULL)
		return (free(arr->items), free(arr), NULL);
	ft_memcpy(arrcpy, arr->items, arr->size * sizeof(int));
	merge_sort(arrcpy, 0, arr->size - 1);
	i = -1;
	while (++i < arr->size)
	{
		if (i > 0 && arrcpy[i] == arrcpy[i - 1])
			return (free(arr->items), free(arr), free(arrcpy), NULL);
		arr->items[i] = get_pos(arrcpy, 0, arr->size - 1, arr->items[i]) + 1;
	}
	free(arrcpy);
	return (arr);
}