/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anammal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 02:00:15 by anammal           #+#    #+#             */
/*   Updated: 2023/06/11 02:00:18 by anammal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

static void	push(t_array *from, t_array *to)
{
	if (from->size > 0)
	{
		ft_memmove(to->items + 1, to->items, sizeof(int) * to->size);
		to->items[0] = from->items[0];
		to->size++;
		from->size--;
		ft_memmove(from->items, from->items + 1, sizeof(int) * from->size);
	}
}

static void	rotate(t_array *s, t_byte d)
{
	int	top;

	if (s->size > 1)
	{
		if (d == 1)
		{
			top = s->items[0];
			ft_memmove(s->items, s->items + 1, sizeof(int) * (s->size - 1));
			s->items[s->size - 1] = top;
		}
		else
		{
			top = s->items[s->size - 1];
			ft_memmove(s->items + 1, s->items, sizeof(int) * (s->size - 1));
			s->items[0] = top;
		}
	}
}

static void	swap(t_array *s)
{
	if (s->size > 1)
	{
		s->items[0] ^= s->items[1];
		s->items[1] ^= s->items[0];
		s->items[0] ^= s->items[1];
	}
}

void	call(t_stack *s, t_byte move)
{
	if (move & SA)
		swap(s->a);
	if (move & SB)
		swap(s->b);
	if (move & RA)
		rotate(s->a, 1);
	if (move & RB)
		rotate(s->b, 1);
	if (move & RRA)
		rotate(s->a, 0);
	if (move & RRB)
		rotate(s->b, 0);
	if (move & PA)
		push(s->b, s->a);
	if (move & PB)
		push(s->a, s->b);
}
