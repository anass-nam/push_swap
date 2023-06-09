#include "checker.h"

static void	tohex(char *move, t_byte hexcode, int len)
{
	ft_bzero(move, len);
	*move = hexcode;
}

static char *isvalid(char *move)
{
	if (ft_strncmp(move, "ss\n", 3))
		tohex(move, SS, 4);
	else if (ft_strncmp(move, "rr\n", 3))
		tohex(move, RR, 4);
	else if (ft_strncmp(move, "rrr\n", 4))
		tohex(move, RRR, 5);
	else if (ft_strncmp(move, "sa\n", 3))
		tohex(move, SA, 4);
	else if (ft_strncmp(move, "sb\n", 3))
		tohex(move, SB, 4);
	else if (ft_strncmp(move, "ra\n", 3))
		tohex(move, RA, 4);
	else if (ft_strncmp(move, "rb\n", 3))
		tohex(move, RB, 4);
	else if (ft_strncmp(move, "rra\n", 4))
		tohex(move, RRA, 5);
	else if (ft_strncmp(move, "rrb\n", 4))
		tohex(move, RRB, 5);
	else if (ft_strncmp(move, "pa\n", 3))
		tohex(move, PA, 4);
	else if (ft_strncmp(move, "pb\n", 3))
		tohex(move, PB, 4);
}

t_list	*get_instructions()
{
	t_list	*list;
	t_list	*tmp;
	char	*move;

	move = "";
	while (move)
	{
		move = get_next_line(STDIN_FILENO);
		if (move)
		{
			tmp = ft_lstnew(isvalid(move));
			if (tmp == NULL)
				return (ft_lstclear(&list, free), free(move), NULL);
			ft_lstadd_back(&list, tmp);
		}
	}
	return (list);
}