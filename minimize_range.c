#include "push_swap.h"

static int	allocate_temp(int *tmp[2], int ll, int rl)
{
	tmp[0] = (int *)malloc(ll * sizeof(int));
	if (tmp[0] == NULL)
		return (0);
	tmp[1] = (int *)malloc(rl * sizeof(int));
	if (tmp[1] == NULL)
		return (free(tmp[0]), 0);
	return (1);
}

static void	merge(int *arr, int llen, int rlen, int *status)
{
	int	*tmp[2];
	int	i[3];

	*status = allocate_temp(tmp, llen, rlen);
	if (*status == 0)
		return ;
	i[0] = -1;
	while (++i[0] < llen)
		tmp[0][i[0]] = arr[i[0]];
	i[0] = -1;
	while (++i[0] < rlen)
		tmp[1][i[0]] = arr[i[0] + llen];
	ft_bzero(i, 3 * sizeof(int));
	while (i[2] < llen + rlen)
	{
		if (i[0] < llen && (i[1] >= rlen || tmp[0][i[0]] < tmp[1][i[1]]))
			arr[i[2]] = tmp[0][i[0]++];
		else
			arr[i[2]] = tmp[1][i[1]++];
		i[2]++;
	}
	free(tmp[0]);
	free(tmp[1]);
}

static void	merge_sort(int *arr, int l, int r, int *status)
{
	int	m;

	if (*status == 1 && l < r)
	{
		m = l + (r - l) / 2;
		merge_sort(arr, l, m, status);
		merge_sort(arr, m + 1, r, status);
		merge(arr + l, m - l + 1, r - m, status);
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
	int	status;
	int	i;

	if (arr == NULL)
		return (NULL);
	arrcpy = (int *)malloc(arr->size * sizeof (int));
	if (arrcpy == NULL)
		return (free(arr->items), free(arr), NULL);
	ft_memcpy(arrcpy, arr->items, arr->size * sizeof(int));
	status = 1;
	merge_sort(arrcpy, 0, arr->size - 1, &status);
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
