/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 20:23:44 by lle-briq          #+#    #+#             */
/*   Updated: 2021/06/13 19:43:08 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	size3_aux(t_stack *stack)
{
	if (stack->a[1] > stack->a[2] && stack->a[2] > stack->a[0])
	{
		ft_putstr("sa\nra\n");
		execute_sa(stack);
		return (execute_ra(stack));
	}
	if (stack->a[1] > stack->a[0] && stack->a[0] > stack->a[2])
	{
		ft_putstr("rra\n");
		return (execute_rra(stack));
	}
}

void	generate_size3(t_stack *stack)
{
	if (stack->a[2] > stack->a[0] && stack->a[0] > stack->a[1])
	{
		ft_putstr("sa\n");
		return (execute_sa(stack));
	}
	if (stack->a[0] > stack->a[1] && stack->a[1] > stack->a[2])
	{
		ft_putstr("sa\nrra\n");
		execute_sa(stack);
		return (execute_rra(stack));
	}
	if (stack->a[0] > stack->a[2] && stack->a[2] > stack->a[1])
	{
		ft_putstr("ra\n");
		return (execute_ra(stack));
	}
	return (size3_aux(stack));
}

void	generate_size5(t_stack *stack)
{
	int	pos;

	while (stack->n_a > 3)
	{
		ft_putstr("pb\n");
		execute_pb(stack);
	}
	generate_size3(stack);
	rev_insert_sort(stack);
	if (stack->n_b > 0)
		rev_insert_sort(stack);
	pos = -1;
	while (++pos < stack->n_a && stack->a[pos] > 0)
		;
	rev_move_to_top(stack, pos);
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