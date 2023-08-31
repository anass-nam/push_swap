/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anammal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 02:44:50 by anammal           #+#    #+#             */
/*   Updated: 2023/06/11 02:44:54 by anammal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

static void	checker_exit(t_stack *stack, t_byte option)
{
	if (option & 0x1)	// free int arr
		free(stack->a->items);
	if (option & 0x2)	// free stack a
		free(stack->a);
	if (option & 0x4)	// free int arr
		free(stack->b->items);
	if (option & 0x8)	// free stack b
		free(stack->b);
	if (option & 0x40)	// error occured (status 1)
	{
		ft_putendl_fd("ERROR", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (option & 0x10)	// sorted
		ft_putendl_fd("OK", STDOUT_FILENO);
	if (option & 0x20)	// unsorted
		ft_putendl_fd("KO", STDOUT_FILENO);
}

int	main(int ac, char const **av)	// main engine of all engines... haha
{
	t_stack	stack;

	if (ac < 2)
		return (0);
	stack.a = parse_args(ac - 1, av + 1);
	if (stack.a == NULL)
		checker_exit(&stack, ERR  & ~(0x1 | 0x2 | 0x4 | 0x8));
	stack.max = stack.a->size;
	stack.b = (t_array *)malloc(sizeof(t_array));
	if (stack.b == NULL)
		checker_exit(&stack, ERR  & ~(0x4 | 0x8));
	stack.b->items = (int *)malloc(stack.max * sizeof(int));
	if (stack.b->items == NULL)
		checker_exit(&stack, ERR  & ~(0x8));
	stack.b->size = 0;
	checker_exit(&stack, checker_sorter(&stack));
	return (0);
}
