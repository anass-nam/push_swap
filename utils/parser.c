#include "utils.h"

static int	    ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

static void     check_double(int *arr, int size)
{
    int i;

    while (size--)
    {
        i = size;
        while (i--)
            if (arr[size] == arr[i])
                err("Duplicate items");
    }
}

static int	    parse_int(const char *str)
{
	long int	r;
	int			s;

	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	s = 1;
	if ((*str == '-' || *str == '+') && ft_isdigit(*(str + 1)))
	    s -= (*(str++) - 43);
	r = 0;
	while (ft_isdigit(*str))
		r = r * 10 + ((*str++) - 48);
	if ((r > 2147483648 && s == -1) || r > 2147483647 || *str)
		err("Invalid item");
	return (r * s);
}

int     *parse_items(char const**s_items, int size)
{
    int *items;
    int i;

    items = (int *)malloc(sizeof(int) * size);
    if (!items)
        err("malloc failed");
    i = -1;
    while (++i < size)
        items[i] = parse_int(s_items[size - i - 1]);
    check_double(items, size);
    return items;
}
