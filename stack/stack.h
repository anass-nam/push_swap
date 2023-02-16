#ifndef STACK_H
# define STACK_H

# include <unistd.h>
# include <stdlib.h>
# include "../utils/utils.h"

# define EMPTY -1
# define LESS 0

# define SA "sa"
# define SB "sb"
# define SS "ss"
# define PA "pa"
# define PB "pb"
# define RA "ra"
# define RB "rb"
# define RR "rr"
# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"

typedef struct s_stack
{
	int		*items;
	int		*rank;
	int		max;
	int		top;
}			t_stack;

t_stack	*init_stack(int max, int **items);
// moves
void	swap(t_stack **s);
void	rot(t_stack **s);
void	rev_rot(t_stack **s);
void	push(t_stack **src, t_stack **dst);
void    call(char *o, t_stack **a, t_stack **b);

#endif