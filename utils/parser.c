#include "utils.h"

static int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

static int	check_double(int *items, int len, int item)
{
	while (len--)
		if (items[len] == item)
			return (1);
	return (0);
}

static int	check_chars(char **d, int size)
{
	int i;

	while (size--)
	{
		i = 0;
		while (d[size][i])
			if (!ft_isdigit(d[size][i++]))
				return (0);
	}
	return (1);
}

static int	ft_atoi(const char *str)
{
	long int	r;
	int			s;

	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	s = 1;
	if (*str == '-' && ft_isdigit(*(char *)(str + 1)))
	{
		s = -1;
		str++;
	}
	else if (*str == '+' && ft_isdigit(*(char *)(str + 1)))
		str++;
	r = 0;
	while (ft_isdigit(*str))
		r = r * 10 + ((*str++) - 48);
	if (r > 2147483648 && s < 0)
		return (0);
	else if (r > 2147483647)
		return (-1);
	return (r * s);
}

int	*get_items(char **d, int size)
{
	int	i;
	int	*items;

	i = 0;
	items = NULL;
	if (!size)
		exit(1);
	if (check_chars(d, size))
	{
		items = (int *)malloc(sizeof(int) * size);
		while (i < size)
		{
			items[i] = ft_atoi(d[size - i - 1]);
			if ((!items[i] && d[size - i - 1][0] == '-')
			|| (d[size - i - 1][0] != '-' && items[i] == -1)
			|| check_double(items, i, items[i]))
				return (free(items), NULL);
			i++;
		}
	}
	return (items);
}

