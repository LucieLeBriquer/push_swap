/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:52:38 by lle-briq          #+#    #+#             */
/*   Updated: 2021/05/03 16:58:21 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_sa(t_stack *stack)
{
	int	swap;

	if (stack->n_a <= 1)
		return ;
	ft_printf("%d\n", stack->n_a);
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
	while (++i < stack->n_b)
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
	while (++i < stack->n_a)
		stack->a[i] = stack->a[i + 1];
	stack->n_b++;
	stack->n_a--;
	stack->b[0] = push;
}

void	execute_ra(t_stack *stack)
{
	int	swap;
	int	i;

	if (stack->n_a < 1)
		return ;
	swap = stack->a[0];
	i = -1;
	while (++i < stack->n_a)
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
	while (++i < stack->n_b)
		stack->b[i] = stack->b[i + 1];
	stack->b[stack->n_b - 1] = swap;
}

void	execute_rr(t_stack *stack)
{
	execute_ra(stack);
	execute_rb(stack);
}

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
