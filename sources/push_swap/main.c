/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 18:00:11 by lle-briq          #+#    #+#             */
/*   Updated: 2021/06/07 20:21:16 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_all(t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < stack->n_b / 2 + 1)
	{
		if (stack->b[i] + 1 == stack->size)
		{
			multiple_rb(stack, i);
			break ;
		}
		else if (stack->b[stack->n_b - i - 1] + 1 == stack->size)
		{
			multiple_rrb(stack, i + 1);
			break ;
		}
	}
	while (stack->n_b > 0)
	{
		execute_pa(stack);
		ft_putstr("pa\n");
	}
}

void	generate_simple(t_stack *stack)
{
	if (stack->size == 1)
		return ;
	if (stack->size == 2)
	{
		if (stack->a[0] < stack->a[1])
			return ;
		ft_putstr("sa\n");
		execute_sa(stack);
		return ;
	}
	if (stack->size == 3)
		return (generate_size3(stack));
	generate_size5(stack);
}

void	generate_code(t_stack *stack)
{
	int	c;
	int	i;

	c = 0;
	if (stack->size <= 5)
		return (generate_simple(stack));
	while (c < stack->nb_chunk)
	{
		while (stack->n_b != stack->chunk[c])
		{
			i = -1;
			while (++i < stack->n_a / 2 + 1)
			{
				if (stack->a[i] < stack->chunk[c])
				{
					multiple_ra(stack, i);
					insert_sort(stack);
					break ;
				}
				else if (stack->a[stack->n_a - i - 1] < stack->chunk[c])
				{
					multiple_rra(stack, i + 1);
					insert_sort(stack);
					break ;
				}
			}
		}
		c++;
	}
	push_all(stack);
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

	if (argc == 1)
		return (0);
	if (check_args(argc, argv))
		return (print_error("Error\n"));
	stack = init_stack(argc, argv);
	if (!stack)
		return (print_error("Error\n"));
	isomorphism(stack);
	if (is_already_sorted(*stack))
		return (0);
	generate_code(stack);
	free_all(stack);
	return (0);
}
