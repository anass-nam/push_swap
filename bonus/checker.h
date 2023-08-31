/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anammal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 01:59:51 by anammal           #+#    #+#             */
/*   Updated: 2023/06/11 01:59:55 by anammal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"	// my one lib of usfull pre-made funcs
# include "get_next_line.h"		// simple and secure function to read from an fd

// exit modes
# define OK 0x1F	// sorted
# define KO 0x2F	// not sorted
# define ERR 0x61	// error occured

// moves
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

// arr type
typedef struct s_array
{
	int	*items;
	int	size;
}	t_array;

// ps stacks struct
typedef struct s_stack
{
	int		max;
	t_array	*a;
	t_array	*b;
}	t_stack;

// bit field (byte)
typedef unsigned char	t_byte;

// checker_parser
t_array	*parse_args(int count, char const **args);
// checker_moves
void	call(t_stack *s, t_byte move);
// checker
t_byte	checker_sorter(t_stack *stack);

#endif
