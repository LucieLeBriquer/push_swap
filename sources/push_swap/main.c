/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 18:00:11 by lle-briq          #+#    #+#             */
/*   Updated: 2021/05/06 14:44:17 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_first_chunk(t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < stack->size)
	{
		if (stack->a[0] < stack->size / 2)
		{
			ft_putstr("pb\n");
			execute_pb(stack);
			ft_printf("%d %d\n", stack->n_a, stack->n_b);
		}
		else
		{
			ft_putstr("ra\n");
			execute_ra(stack);
		}
	}
	print_stack(*stack);
}

void	generate_code(t_stack *stack)
{
	push_first_chunk(stack);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc == 1)
		return (0);
	if (check_args(argc, argv))
		return (print_error("Error\n"));
	stack = init_stack(argc, argv);
	if (!stack)
		return (print_error("Error\n"));
	isomorphism(stack);
	generate_code(stack);
	free_all(stack);
	return (0);
}