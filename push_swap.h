/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anammal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 19:42:22 by anammal           #+#    #+#             */
/*   Updated: 2023/06/09 19:42:26 by anammal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>

# define ERR "Erorr"

# define FREE_SA 0x1	// free stack A
# define FREE_SB 0x2	// free stack B
# define PERR 0x4		// print error
# define EERR 0x8		// exit failure
# define PSFAIL 0xF		// all

# define SA 0x1		// swap top tow elements on stack A
# define SB 0x2		// swap top tow elements on stack B
# define SS 0x3		// SA and SB in same time
# define RA 0x4		// rotate stack A by one
# define RB 0x8		// rotate stack B by one
# define RR 0xC		// RA and RB in same time
# define RRA 0x10	// reverse rotate stack A by one
# define RRB 0x20	// reverse rotate stack B by one
# define RRR 0x30	// RRA and RRB in same time
# define PA 0x40	// push top element of stack B onto stack A
# define PB 0x80	// push top element of stack A onto stack B

typedef struct s_array
{
	int	*items;
	int	size;
}	t_array;

typedef struct s_stack
{
	int		max;
	t_array	*a;
	t_array	*b;
}	t_stack;

typedef unsigned char	t_byte;

void	push_swap(t_stack *s);
void	call(t_stack *stack, t_byte move);
t_array	*parse_args(int count, char const **args);
t_array	*minimize_range(t_array *arr);

#endif
