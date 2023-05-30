#include "push_swap.h"

static int	*parse_int(char	*item)
{
	int		*parsed;
	int		curent;
	int		iszero;

	curent = ft_atoi(item);
	if ((*item == '-' || *item == '+') && ft_isdigit(*(item + 1)))
		item++;
	iszero = 0;
	while (ft_isdigit(*item))
		iszero += *(item++) - '0';
	if (*item != '\0' || ((curent == 0 || curent == -1) && iszero != 0))
		return (NULL);
	parsed = (int *)malloc(sizeof(int));
	if (parsed == NULL)
		return (NULL);
	*parsed = curent;
	return (parsed);
}

static void	add_to_list(t_list **item, char **args)
{
	t_list	*new;

	while (*args)
	{
		new = ft_lstnew(parse_int(*args));
		if (new == NULL || new->content == NULL)
		{
			ft_lstdelone(new, free);
			ft_lstclear(item, free);
			break ;
		}
		ft_lstadd_back(item, new);
		args++;
	}
}

t_list		*parse_args(int count, char const **args)
{
	t_list	*item;
	char	**tmp;

	item = NULL;
	while (count--)
	{
		tmp = ft_split(*args, ' ');
		if (tmp == NULL)
			return (ft_lstclear(&item, free), NULL);
		else if (*tmp == NULL)
			return (ft_lstclear(&item, free), free(tmp), NULL);
		add_to_list(&item, tmp);
		ft_free2d((void *)tmp);
		if (item == NULL)
			return (NULL);
		args++;
	}
	return (item);
}
