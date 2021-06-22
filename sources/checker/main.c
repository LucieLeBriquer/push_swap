/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:48:50 by lle-briq          #+#    #+#             */
/*   Updated: 2021/06/15 19:14:45 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;
	int		args;

	if (argc == 1)
		return (0);
	if (check_args(argc, argv, &args))
		return (print_error("Error\n"));
	stack = malloc(sizeof(t_stack));
	if (!stack || init_stack(argc, argv, args, stack))
		return (print_error("Error\n"));
	if (execute_instructions(stack))
		return (print_error("Error\n"));
	check_sorted(*stack);
	free_all(stack);
	return (0);
}
