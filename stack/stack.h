#ifndef STACK_H
#define STACK_H

# define EMPTY -1

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

#endif