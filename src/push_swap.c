/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anammal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 19:42:13 by anammal           #+#    #+#             */
/*   Updated: 2023/06/09 19:42:17 by anammal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static t_byte	locate(int *arr, int target)
{
	int	i;

	i = 0;
	while (i < target / 2 && arr[i] != target)
		i++;
	return (arr[i] == target);
}

static void	divide_items(t_stack *s)
{
	int	*top_a;
	int	*top_b;
	int	pivot;
	int	i;

	top_a = s->a->items;
	top_b = s->b->items;
	pivot = s->max / (13 - (s->max <= 100) * 8);
	i = 1;
	while (s->a->size > 3)
	{
		if (*top_a <= i + pivot && *top_a < s->max - 2)
		{
			call(s, PB);
			if (*top_b > i)
				call(s, RB);
			i++;
		}
		else
			call(s, RA);
	}
}

static void	merge_items(t_stack *s)
{
	int	*top;
	int	max;

	top = s->b->items;
	while (s->b->size)
	{
		max = s->b->size;
		if (locate(s->b->items, max))
		{
			if (max == *top)
				call(s, PA);
			else
				call(s, RB);
		}
		else
			call(s, RRB);
	}
}

void	push_swap(t_stack *s)
{
	int	*top;

	top = s->a->items;
	if (s->a->size == 1)
		return ;
	else if (s->a->size == 2)
	{
		if (top[0] > top[1])
			call(s, SA);
		return ;
	}
	divide_items(s);
	while (!(top[0] < top[1] && top[1] < top[2]))
	{
		if (top[0] < top[1] && top[0] > top[2])
			call(s, RRA);
		else if (top[0] > top[1] && top[0] > top[2])
			call(s, RA);
		else
			call(s, SA);
	}
	merge_items(s);
}
