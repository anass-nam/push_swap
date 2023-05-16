#include "push_swap.h"




int main(int ac, char const **av)
{
	t_array	*arr;

	if (ac < 2)
		return (1);
	arr = parse_args(ac - 1, av + 1);
	if (arr == NULL)
		return (1);
	return 0;
}
