#include "push_swap.h"

void	printarr(t_array *arr)
{
	int	i;

	i = 0;
	while (i < arr->size)
	{
		ft_putnbr_fd(arr->items[i], STDOUT_FILENO);
		ft_putchar_fd(' ', STDOUT_FILENO);
		i++;
	}
	ft_putchar_fd('\n', STDOUT_FILENO);
}

static void	print_move(t_byte move)
{
	if (move == SS)
		ft_putendl_fd("ss", STDOUT_FILENO);
	else if (move == RR)
		ft_putendl_fd("rr", STDOUT_FILENO);
	else if (move == RRR)
		ft_putendl_fd("rrr", STDOUT_FILENO);
	else if (move & SA)
		ft_putendl_fd("sa", STDOUT_FILENO);
	else if (move & SB)
		ft_putendl_fd("sb", STDOUT_FILENO);
	else if (move & RA)
		ft_putendl_fd("ra", STDOUT_FILENO);
	else if (move & RB)
		ft_putendl_fd("rb", STDOUT_FILENO);
	else if (move & RRA)
		ft_putendl_fd("rra", STDOUT_FILENO);
	else if (move & RRB)
		ft_putendl_fd("rrb", STDOUT_FILENO);
	else if (move & PA)
		ft_putendl_fd("pa", STDOUT_FILENO);
	else if (move & PB)
		ft_putendl_fd("pb", STDOUT_FILENO);
}

t_byte	*calculate(t_array *arr, t_array *lis)
{
	t_byte	*mvs1;
	t_byte	*mvs2;
	int		i;

	mvs1 = (t_byte *)malloc(arr->size * sizeof(t_byte));
	mvs1 = ft_memset(mvs1, PB, arr->size);
	i = 0;
	while (i < lis->size)
	{
		mvs1[lis->items[i]] = RA;
		i++;
	}
	i = arr->size;
	while (i--)
	{
		print_move(mvs1[i]);
	}
	
	
	


	return (mvs1);
}



int main(int ac, char const **av)
{
	t_array	*arr;
	t_array	*lis;

	arr = parse_args(ac - 1, av + 1);
	if (arr == NULL)
		return (0);
	printarr(arr);
	lis = get_lis(arr);
	if (lis == NULL)
		return (0);
	printarr(lis);
	
	calculate(arr, lis);

	return 0;
}
