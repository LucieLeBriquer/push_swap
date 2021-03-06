/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 21:03:07 by lle-briq          #+#    #+#             */
/*   Updated: 2021/06/24 23:09:43 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	generate_code(t_stack *stack)
{
	int	c;

	c = 0;
	if (stack->size <= 5)
		return (generate_simple(stack));
	stack->nb_chunk = 4;
	if (stack->size >= 500)
		stack->nb_chunk = 7;
	if (define_chunks(stack))
		generate_complex(stack);
}

int	is_already_sorted(t_stack stack)
{
	int	i;

	i = 0;
	while (i < stack.n_a - 1)
	{
		if (stack.a[i] > stack.a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

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
	isomorphism(stack);
	if (is_already_sorted(*stack))
	{
		free_all(stack);
		return (0);
	}
	generate_code(stack);
	print_reduce_moves(*stack);
	free_all(stack);
	return (0);
}
