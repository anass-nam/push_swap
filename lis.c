#include "push_swap.h"

typedef struct s_lis
{
	int	*tail;
	int	*prev;
	int	len;
}	t_lis;

static int		get_pos(int a[], int i[], int l, int r, int v)
{
	int	m;

	while (r - l > 1)
	{
		m = l + (r - l) / 2;
		if (a[i[m]] >= v)
			r = m;
		else
			l = m;
	}

    return (r);
}

static void		free_lis(t_lis **lis, int last)
{
	int	i;

	i = 0;
	while (i < last)
	{
		free(lis[i]->tail);
		lis[i]->tail = NULL;
		free(lis[i]->prev);
		lis[i]->prev = NULL;
		free(lis[i]);
		lis[i] = NULL;
		i++;
	}
	free(lis);
}

static t_lis	**init_lis(int len)
{
	t_lis	**lis;
	int		i;

	lis = (t_lis **)malloc(sizeof(t_lis *) * len);
	if (lis == NULL)
		return (NULL);
	i = -1;
	while (++i < len)
	{
		lis[i] = (t_lis *)malloc(sizeof(t_lis));
		if (lis[i] == NULL)
			return (free_lis(lis, i), NULL);
		lis[i]->tail = (int *)malloc(sizeof(int) * len);
		if (lis[i]->tail == NULL)
			return (free(lis[i]), free_lis(lis, i), NULL);
		lis[i]->prev = (int *)malloc(sizeof(int) * len);
		if (lis[i]->prev == NULL)
			return (free(lis[i]->tail), free(lis[i]), free_lis(lis, i), NULL);
		lis[i]->tail[0] = i;
		lis[i]->prev[0] = -1;
		lis[i]->len = 1;
	}
	
	return (lis);
}

static void		construct_lis(t_lis *lis, int *arr, int len)
{
	int	s;
	int	i;
	int	pos;

	s = lis->tail[0];
	i = 0;
	while (++i < len)
	{
		if (arr[(s + i) % len] < arr[lis->tail[0]])
			lis->tail[0] = (s + i) % len;
		else if (arr[(s + i) % len] > arr[lis->tail[lis->len - 1]])
		{
			lis->prev[(s + i) % len] = lis->tail[lis->len - 1];
			lis->tail[lis->len++] = (s + i) % len;
		}
		else
		{
			pos = get_pos(arr, lis->tail, -1, lis->len - 1, arr[(s + i) % len]);
			lis->prev[(s + i) % len] = lis->tail[pos - 1];
			lis->tail[pos] = (s + i) % len;
		}
	}
}

static t_array	*finalize_lis(t_lis *lis, int r)
{
	t_array	*lis_indices;
	int		i;
	int		j;

	lis_indices = (t_array *) malloc(sizeof(t_array));
	if (lis_indices == NULL)
		return (NULL);
	lis_indices->items = (int*) malloc((lis->len) * sizeof(int));
	if (lis_indices->items == NULL)
		return (free(lis_indices), NULL);
	i = 0;
	j = lis->tail[lis->len - 1];
	lis_indices->size = lis->len;
	while (i < lis->len)
	{
		lis_indices->items[(i + r) % lis->len] = j;
		j = lis->prev[j];
		i++;
	}
	return (lis_indices);
}

t_array *get_lis(t_array *arr)
{
	t_lis	**lis;
	t_array	*valid_lis;
	int		i;
	int		b_lis;

	lis = init_lis(arr->size);
	if (lis == NULL)
		return (NULL);
	i = -1;
	while (++i < arr->size)
		construct_lis(lis[i], arr->items, arr->size);
	i = -1;
	b_lis = 0;
	while (++i < arr->size)
		if (lis[i]->len > lis[b_lis]->len)
			b_lis = i;
	valid_lis = finalize_lis(lis[b_lis], b_lis);
	free_lis(lis, arr->size);
	return (valid_lis);
}
