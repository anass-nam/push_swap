/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anammal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 01:59:03 by anammal           #+#    #+#             */
/*   Updated: 2023/06/11 01:59:08 by anammal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

static t_byte	issorted(t_stack *s)	// sort status
{
	int	*top;
	int	i;

	if (s->b->size == 0)
	{
		top = s->a->items;
		i = 0;
		while (++i < s->max)
			if (top[i - 1] > top[i])
				return (KO);
		return (OK);
	}
	return (KO);
}

static t_byte	isvalid(char *move)		// moves filter
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

t_byte	checker_sorter(t_stack *stack)	// checker engine haha...
{
	char	*mv;
	t_byte	mv_hex;

	mv = "";
	while (mv != NULL)
	{
		mv = get_next_line(STDIN_FILENO);
		if (mv)
		{
			mv_hex = isvalid(mv);
			free(mv);
			if (mv_hex)
				call(stack, mv_hex);
			else
				return (ERR);
		}
	}
	return (issorted(stack));
}
