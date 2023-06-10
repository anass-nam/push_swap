#include "checker.h"

static t_byte isvalid(char *move)
{
	if (!ft_strncmp(move, "ss\n", 3))
		return (SS);
	else if (!ft_strncmp(move, "rr\n", 3))
		return (RR);
	else if (!ft_strncmp(move, "rrr\n", 4))
		return (RRR);
	else if (!ft_strncmp(move, "sa\n", 3))
		return (SA);
	else if (!ft_strncmp(move, "sb\n", 3))
		return (SB);
	else if (!ft_strncmp(move, "ra\n", 3))
		return (RA);
	else if (!ft_strncmp(move, "rb\n", 3))
		return (RB);
	else if (!ft_strncmp(move, "rra\n", 4))
		return (RRA);
	else if (!ft_strncmp(move, "rrb\n", 4))
		return (RRB);
	else if (!ft_strncmp(move, "pa\n", 3))
		return (PA);
	else if (!ft_strncmp(move, "pb\n", 3))
		return (PB);
	return (0);
}

static char *tohex(char *move)
{
	*move = isvalid(move);
	ft_bzero(move + 1, ft_strlen(move + 1));
	return (move);
}

t_list	*get_instructions()
{
	t_list	*list;
	t_list	*tmp;
	char	*move;

	list = NULL;
	move = "";
	while (move)
	{
		tmp = NULL;
		move = get_next_line(STDIN_FILENO);
		if (move)
		{
			move = tohex(move);
			if (*move)
				tmp = ft_lstnew(move);
			if (tmp == NULL)
				return (ft_lstclear(&list, free), free(move), NULL);
			ft_lstadd_back(&list, tmp);
		}
	}
	return (list);
}