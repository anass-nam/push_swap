#include "push_swap.h"

static int	get_pos(int a[], int t[], int l, int r, int v)
{
	int	m;

	while (r - l > 1)
	{
		m = l + (r - l) / 2;
		if (a[t[m]] >= v)
			r = m;
		else
			l = m;
	}

    return (r);
}

static void free_lis(t_lis **lis, int last)
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

static int		*finalize_lis(t_lis *lis)
{
	int		*lis_indices;
	int		i;
	int		j;

	lis_indices = (int*) malloc((lis->len) * sizeof(int));
	if (lis_indices == NULL)
		return (NULL);
	i = lis->len - 1;
	j = lis->tail[i];
	lis_indices[i + 1] = -1;
	while (i >= 0)
	{
		lis_indices[i] = j;
		j = lis->prev[j];
		i--;
	}
	return (lis_indices);
}

int *get_lis(int *arr, int len)
{
	t_lis	**lis;
	int		*valid_lis;
	int		i;
	int		b_lis;

	lis = init_lis(len);
	if (lis == NULL)
		return (NULL);
	i = -1;
	while (++i < len)
		construct_lis(lis[i], arr, len);
	i = -1;
	b_lis = 0;
	while (++i < len)
		if (lis[i]->len > lis[b_lis]->len)
			b_lis = i;
	valid_lis = finalize_lis(lis[b_lis]);
	free_lis(lis, len);
	return (valid_lis);
}

// int main(void)
// {
//     int arr[] = {8,0,4,2,3,9,5,6,7};
//     int len = sizeof(arr)/sizeof(arr[0]);
//     int *l = get_lis(arr, len);
// 	for (size_t i = 0; l[i] != -1; i++)
// 	{
// 		ft_putnbr_fd(l[i], STDOUT_FILENO);
// 		ft_putstr_fd(" -> ", STDOUT_FILENO);
// 		ft_putnbr_fd(arr[l[i]], STDOUT_FILENO);
// 		ft_putchar_fd('\n', STDOUT_FILENO);
// 	}
	
//     return 0;
// }




