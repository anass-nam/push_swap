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
	if (option & 0x1)
	{
		free(stack->a->items);
		free(stack->a);
	}
	if (option & 0x2)
	{
		free(stack->b->items);
		free(stack->b);
	}
	if (option & 0x4)
		ft_lstclear(&(stack->moves), free);
	if (option & 0x8)
		ft_putendl_fd("Error", STDERR_FILENO);
	else if (option & 0x10)
		ft_putendl_fd("KO", STDOUT_FILENO);
	else if (option & 0x20)
		ft_putendl_fd("OK", STDOUT_FILENO);
	if (option & 0x40)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_SUCCESS);
}

static void	checker_init(t_stack *s, int ac, char const **av)
{
	s->a = parse_args(ac, av);
	if (s->a == NULL)
		checker_exit(s, ERR & ~(0x1 | 0x2 | 0x4));
	s->max = s->a->size;
	s->b = (t_array *)malloc(sizeof(t_array));
	if (s->b == NULL)
		checker_exit(s, ERR & ~(0x2 | 0x4));
	s->b->items = (int *)malloc(s->max * sizeof(int));
	if (s->b->items == NULL)
		checker_exit(s, ERR & ~(0x4));
	s->b->size = 0;
	s->moves = get_instructions();
	// if (s->moves == NULL && issorted(s))
	// 	checker_exit(s, OK & ~(0x4));
	// if (s->moves == NULL)
	// 	checker_exit(s, ERR & ~(0x4));
}

int	main(int ac, char const **av)
{
	t_stack	stack;
	t_byte	status;

	if (ac < 2)
		return (0);
	checker_init(&stack, ac - 1, av + 1);
	status = checker_sort(&stack);
	checker_exit(&stack, status);
	return (0);
}
