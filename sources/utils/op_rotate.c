/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:52:38 by lle-briq          #+#    #+#             */
/*   Updated: 2021/06/15 18:25:08 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_ra(t_stack *stack)
{
	int	swap;
	int	i;

	if (stack->n_a < 1)
		return ;
	swap = stack->a[0];
	i = -1;
	while (++i + 1 < stack->n_a)
		stack->a[i] = stack->a[i + 1];
	stack->a[stack->n_a - 1] = swap;
}

void	execute_rb(t_stack *stack)
{
	int	swap;
	int	i;

	if (stack->n_b < 1)
		return ;
	swap = stack->b[0];
	i = -1;
	while (++i + 1 < stack->n_b)
		stack->b[i] = stack->b[i + 1];
	stack->b[stack->n_b - 1] = swap;
}

void	execute_rr(t_stack *stack)
{
	execute_ra(stack);
	execute_rb(stack);
}
