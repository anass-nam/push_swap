#include "push_swap.h"

static void	exit_ps(t_stack *s, t_byte o)
{
	if (o & FREE_SA)
	{
		free(s->a->items);
		free(s->a);
	}
	if (o & FREE_SB)
	{
		free(s->b->items);
		free(s->b);
	}
	if (o & PERR)
		ft_putendl_fd(ERR, STDERR_FILENO);
	if (o & EERR)
		exit(EXIT_FAILURE);
}

static void	init_ps(t_stack *s, int ac, char const **av)
{
	s->a = parse_args(ac, av);
	s->a = minimize_range(s->a);
	if (s->a == NULL)
		exit_ps(s, PERR | EERR);
	s->max = s->a->size;
	s->b = (t_array *)malloc(sizeof(t_array));
	if (s->b == NULL)
		exit_ps(s, PSFAIL & ~FREE_SB);
	s->b->items = (int *)ft_calloc(s->max, sizeof(int));
	if (s->b->items == NULL)
		exit_ps(s, PSFAIL);
	s->b->size = 0;
}

int	main(int ac, char const **av)
{
	t_stack	stack;

	if (ac < 2)
		return (0);
	init_ps(&stack, ac - 1, av + 1);
	push_swap(&stack);
	exit_ps(&stack, PSFAIL & ~PERR);
	return (0);
}
