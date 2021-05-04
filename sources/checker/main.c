/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:48:50 by lle-briq          #+#    #+#             */
/*   Updated: 2021/05/04 23:18:13 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_all(t_stack *stack)
{
	if (stack->a)
		free(stack->a);
	if (stack->b)
		free(stack->b);
	if (stack)
		free(stack);
}

static void	fill_stack(t_stack *stack, char **argv)
{
	int	i;

	i = 1;
	while (i < stack->size)
	{
		stack->a[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	stack->n_a = stack->size - 1;
	stack->n_b = 0;
}

t_stack	*init_stack(int argc, char **argv)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->a = malloc(argc * sizeof(int));
	stack->b = malloc(argc * sizeof(int));
	if (!stack->a || !stack->b)
	{
		free_all(stack);
		return (NULL);
	}
	stack->size = argc;
	fill_stack(stack, argv);
	return (stack);
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
		return (print_error("Allocation issues\n"));
	if (duplicate(*stack))
	{
		free_all(stack);
		return (print_error("Error\n"));
	}
	print_stack(*stack);
	execute_instructions(stack);
	check_sorted(*stack);
	free_all(stack);
	return (0);
}
