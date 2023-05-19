#include "push_swap.h"

static int	isvalid_arg(char const *arg)
{
	int	i;

	i = 0;
	while (*arg != '\0')
	{
		while (ft_isspace(*arg))
			arg++;
		if ((*arg == '-' || *arg == '+') && ft_isdigit(*(arg + 1)))
			arg++;
		while (ft_isdigit(*arg))
			arg++;
		if (!ft_isdigit(*arg) && !ft_isspace(*arg) && *arg != '\0')
			return (0);
		i++;
	}
	return (i);
}

static char	*join_args(int count, char const **args)
{
	char	*joined_args;
	char	*tmp;

	joined_args = ft_strdup("");
	while (count--)
	{
		if (isvalid_arg(*args))
		{
			tmp = joined_args;
			joined_args = ft_strjoin(joined_args, " ");
			free(tmp);
			tmp = joined_args;
			joined_args = ft_strjoin(joined_args, *args);
			free(tmp);
			if (joined_args == NULL)
				return (NULL);
		}
		else
			return (free(joined_args), NULL);
		args++;
	}
	return (joined_args);
}

static t_array	*parse_int_array(char **items)
{
	t_array	*arr;
	int		i;

	arr = (t_array *)malloc(sizeof(t_array));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (*(items + i))
		i++;
	arr->items = (int *)malloc(i * sizeof(int));
	if (arr->items == NULL)
		return (free(arr), NULL);
	arr->size = i;
	while (i--)
	{
		arr->items[i] = ft_atoi(*items);
		if ((**items == '-' && arr->items[i] == 0)
			|| (**items != '-' && arr->items[i] == -1))
			return (free(arr), free(arr->items), NULL);
		items++;
	}
	return (arr);
}

static t_array	*checkdup(t_array *arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr && i < arr->size)
	{
		j = i + 1;
		while (j < arr->size)
		{
			if (arr->items[i] == arr->items[j])
				return (free(arr->items), free(arr), NULL);
			j++;
		}
		i++;
	}
	return (arr);
}

t_array			*parse_args(int count, char const **args)
{
	char	*joined_args;
	char	**splited_args;
	t_array	*arr;

	joined_args = join_args(count, args);
	if (joined_args == NULL)
		return (NULL);
	splited_args = ft_split(joined_args, ' ');
	if (splited_args == NULL)
		return (free(joined_args), NULL);
	if (*splited_args == NULL)
		return (free(joined_args), free(splited_args), NULL);
	arr = parse_int_array(splited_args);
	ft_free2d((void **)splited_args);
	return (checkdup(arr));
}
