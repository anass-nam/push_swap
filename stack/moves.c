#include "stack.h"

static void both(void (*f)(t_stack **), t_stack **a, t_stack **b)
{
    f(a);
    f(b);
}

void    call(char *o, t_stack **a, t_stack **b)
{
	if (!o)
		return;
    else if (!ft_strcmp(o, "sa"))
        swap(a);
    else if (!ft_strcmp(o, "sb"))
        swap(b);
    else if (!ft_strcmp(o, "ss"))
        both(swap, a, b);
    else if (!ft_strcmp(o, "pa"))
        push(b, a);
    else if (!ft_strcmp(o, "pb"))
        push(a, b);
    else if (!ft_strcmp(o, "ra"))
        rot(a);
    else if (!ft_strcmp(o, "rb"))
        rot(b);
    else if (!ft_strcmp(o, "rr"))
        both(rot, a, b);
    else if (!ft_strcmp(o, "rra"))
        rev_rot(a);
    else if (!ft_strcmp(o, "rrb"))
        rev_rot(b);
    else if (!ft_strcmp(o, "rrr"))
        both(rev_rot, a, b);
    ft_putendl_fd(o, 1);
}