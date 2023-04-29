#include "push_swap.h"

int	isvalid(char const *item)
{
	if (*item == '-' || *item == '+')
		item++;
	while (*item && ft_isdigit(*item))
		item++;
	return (*item == 0);
}

int	*parse_args(int count, char const **args)
{
	int	i;
	int	*items;

	items = (int *)malloc(sizeof(int) * count);
	if (items == NULL)
		return (NULL);
	i = 0;
	while (i < count)
	{
		if (isvalid(args[i]) == 0 || *args[i] == 0)
			return (free(items), NULL);
		items[i] = ft_atoi(args[i]);
		if ((*args[i] == '-' && items[i] == 0)
			|| (*args[i] != '-' && items[i] == -1))
			return (free(items), NULL);
		i++;
	}
	return (items);
}

