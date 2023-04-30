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
	while (count--)
	{
		if (*args[i] == 0 || isvalid(args[i]) == 0)
			return (free(items), NULL);
		items[count] = ft_atoi(args[i]);
		if ((*args[i] == '-' && items[count] == 0)
			|| (*args[i] != '-' && items[count] == -1))
			return (free(items), NULL);
		i++;
	}
	return (items);
}

