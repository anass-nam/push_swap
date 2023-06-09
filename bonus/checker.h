#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include "get_next_line.h"

# define OK 0x27	// sorted
# define KO 0x17	// not sorted
# define ERR 0x4F// error occured

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
	t_list	*moves;
}	t_stack;

typedef unsigned char	t_byte;

t_array	*parse_args(int count, char const **args);
t_list	*get_instructions();
void	call(t_stack *s, t_byte move);
t_byte	checker_sort(t_stack *s);

#endif