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
	while (++i < stack->size && stack->n_b < stack->chunk[0])
	{
		if (stack->a[0] < stack->chunk[0])
		{
			ft_putstr("pb\n");
			execute_pb(stack);
		}
		else
		{
			ft_putstr("ra\n");
			execute_ra(stack);
		}
	}
	print_stack(*stack);
}

void	push_second_chunk(t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < stack->n_b && stack->n_b >= stack->chunk[1])
	{
		if (stack->b[0] >= stack->chunk[1])
		{
			ft_putstr("pa\n");
			execute_pa(stack);
		}
		else
		{
			ft_putstr("rb\n");
			execute_rb(stack);
		}
	}
	print_stack(*stack);
}

void	push_third_chunk(t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < stack->n_b && stack->n_b >= stack->chunk[2])
	{
		if (stack->b[0] >= stack->chunk[2])
		{
			ft_putstr("pa\n");
			execute_pa(stack);
		}
		else
		{
			ft_putstr("rb\n");
			execute_rb(stack);
		}
	}
	print_stack(*stack);
}

void	push_fourth_chunk(t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < stack->n_b && stack->n_b >= stack->chunk[3])
	{
		if (stack->b[0] >= stack->chunk[3])
		{
			ft_putstr("pa\n");
			execute_pa(stack);
		}
		else
		{
			ft_putstr("rb\n");
			execute_rb(stack);
		}
	}
	print_stack(*stack);
}

void	generate_code(t_stack *stack)
{
	push_first_chunk(stack);
	push_second_chunk(stack);
	push_third_chunk(stack);
	push_fourth_chunk(stack);
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
	print_stack(*stack);
	generate_code(stack);
	free_all(stack);
	return (0);
}