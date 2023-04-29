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
			lis->prev[i] = lis->tail[lis->len - 1];
			lis->tail[lis->len++] = (s + i) % len;
		}
		else
		{
			pos = get_pos(arr, lis->tail, -1, len -1, arr[(s + i) % len]);
			lis->prev[i] = lis->tail[pos - 1];
			lis->tail[pos] = (s + i) % len;
		}
	}
}

int *get_lis(int *arr, int len)
{
	t_lis	**lis;
	int		i;

	lis = init_lis(len);
	if (lis == NULL)
		return (NULL);
	i = -1;
	while (++i < len)
		construct_lis(lis[i], arr, len);
	i = 0;
	while (i < len)
	{
		ft_putnbr_fd(lis[i]->len, STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
		i++;
	}
	free_lis(lis, len);

	return (NULL);
}

int main(void)
{
    int arr[] = {-4,4,1,2,-6,6,-2,-1,0,5,11,8,7,9};
    int len = sizeof(arr)/sizeof(arr[0]);
    get_lis(arr, len);
    return 0;
}




