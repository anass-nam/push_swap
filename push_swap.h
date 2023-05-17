#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include "libft.h"

# define ERR "Erorr"
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

typedef struct	s_array
{
	int	*items;
	int	size;
}	t_array;

typedef struct s_stack
{
	int	*items;
	int	top;
}	t_stack;

typedef struct s_ps
{
	t_stack	*a;
	t_stack	*b;
}	t_ps;

typedef struct s_lis
{
	int	*tail;
	int	*prev;
	int	len;
}	t_lis;


typedef unsigned char t_byte;

t_array	*parse_args(int count, char const **args);
void	call(t_ps *stack, t_byte move);
t_array	*get_lis(t_array *arr);
t_byte	*calculate(t_array *arr, t_array *lis);
int		get_pos(int a[], int t[], int l, int r, int v);
t_byte	*calc_first_mvs(t_array *arr, t_array *lis);
int		get_pos2(int a[], int l, int r, int v);

#endif