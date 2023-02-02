#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define EMPTY -1
# define ERR "Erorr\n"

typedef struct s_stack_objet
{
	int		*items;
	int		max;
	int		top;
}			t_so;

typedef struct s_stack_holder
{
	t_so	*a;
	t_so	*b;
}			t_stack;

// moves
void	sa(t_stack **s);
void	sb(t_stack **s);
void	ss(t_stack **s);
void	pa(t_stack **s);
void	pb(t_stack **s);
void	ra(t_stack **s);
void	rb(t_stack **s);
void	rr(t_stack **s);
void	rra(t_stack **s);
void	rrb(t_stack **s);
void	rrr(t_stack **s);
// parse and get stack values
int		*get_items(char **d, int size);
// init the stack object
t_stack	*init_stack(int max, int **items);


#endif