/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:52:38 by lle-briq          #+#    #+#             */
/*   Updated: 2021/05/04 23:14:13 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_rra(t_stack *stack)
{
	int	swap;
	int	i;

	if (stack->n_a < 1)
		return ;
	swap = stack->a[stack->n_a - 1];
	i = stack->n_a;
	while (--i > 0)
		stack->a[i] = stack->a[i - 1];
	stack->a[0] = swap;
}

void	execute_rrb(t_stack *stack)
{
	int	swap;
	int	i;

	if (stack->n_b < 1)
		return ;
	swap = stack->b[stack->n_b - 1];
	i = stack->n_b;
	while (--i > 0)
		stack->b[i] = stack->b[i - 1];
	stack->b[0] = swap;
}

void	execute_rrr(t_stack *stack)
{
	execute_rra(stack);
	execute_rrb(stack);
}
