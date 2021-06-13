/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:52:38 by lle-briq          #+#    #+#             */
/*   Updated: 2021/06/13 19:50:07 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_pa(t_stack *stack)
{
	int	i;
	int	push;

	if (stack->n_b < 1)
		return ;
	push = stack->b[0];
	i = stack->n_a + 1;
	while (--i > 0)
		stack->a[i] = stack->a[i - 1];
	i = -1;
	while (++i + 1 < stack->n_b)
		stack->b[i] = stack->b[i + 1];
	stack->n_a++;
	stack->n_b--;
	stack->a[0] = push;
}

void	execute_pb(t_stack *stack)
{
	int	i;
	int	push;

	if (stack->n_a < 1)
		return ;
	push = stack->a[0];
	i = stack->n_b + 1;
	while (--i > 0)
		stack->b[i] = stack->b[i - 1];
	i = -1;
	while (++i + 1 < stack->n_a)
		stack->a[i] = stack->a[i + 1];
	stack->n_b++;
	stack->n_a--;
	stack->b[0] = push;
}
