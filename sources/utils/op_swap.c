/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:52:38 by lle-briq          #+#    #+#             */
/*   Updated: 2021/05/04 23:15:15 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_sa(t_stack *stack)
{
	int	swap;

	if (stack->n_a <= 1)
		return ;
	swap = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = swap;
}

void	execute_sb(t_stack *stack)
{
	int	swap;

	if (stack->n_b <= 1)
		return ;
	swap = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = swap;
}

void	execute_ss(t_stack *stack)
{
	execute_sa(stack);
	execute_sb(stack);
}
