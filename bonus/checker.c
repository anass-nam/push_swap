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

static t_byte	issorted(t_stack *s)
{
	int	*top;
	int	i;

	top = s->a->items;
	i = 1;
	if (s->b->size == 0)
	{
		while (i < s->a->size && top[i - 1] < top[i])
			i++;
		if (i == s->a->size)
			return (OK);
	}
	return (KO);
}

t_byte	checker_sort(t_stack *s)
{
	t_list	*move;

	move = s->moves;
	while (move)
	{
		call(s, *(t_byte *)(move->content));
		move = move->next;
	}
	return (issorted(s));
}
