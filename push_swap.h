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

t_stack	*init_stack(int max, int **items);
void	swap_a(t_stack **s);
void	swap_b(t_stack **s);
void	swap_s(t_stack **s);
void	push_a(t_stack **s);
void	push_b(t_stack **s);
void	rot_a(t_stack **s);
void	rot_b(t_stack **s);
void	rot_r(t_stack **s);
void	rrot_a(t_stack **s);
void	rrot_b(t_stack **s);
void	rrot_r(t_stack **s);
int		*get_items(char **d, int size);


#endif