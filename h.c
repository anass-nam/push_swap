#include "push_swap.h"

void    arr_free(void **ptr)
{
    free(*ptr);
    *ptr = NULL;
}

void    err(char *msg, void (*freemem)(void **), void **ptr)
{
    if (freemem && ptr)
        freemem(ptr);
    printf("%s: %s\n", ERR, msg);
    exit(1);
}

int	    ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int     check_double(int *arr, int size)
{
    int i;

    while (size--)
    {
        i = size;
        while (i--)
            if (arr[size] == arr[i])
                return (1);
    }
    return (0);
}

int	    parse_int(int **items, const char *str)
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
		err("Invalid item", arr_free, (void **)items);
	return (r * s);
}

int     *parse_items(char const**s_items, int size)
{
    int *items;
    int i;

    items = (int *)malloc(sizeof(int) * size);
    if (!items)
        err("malloc failed", NULL, NULL);
    i = size;
    while (i--)
        items[i] = parse_int(&items, s_items[i]);
    if (check_double(items, size))
        err("Duplicate items", arr_free, (void **)&items);
    return items;
}

int main(int ac, char const **av)
{
    int *items;

    items = parse_items(av + 1, --ac);
    while (ac--)
        printf("%d\n", items[ac]);
    return 0;
}


