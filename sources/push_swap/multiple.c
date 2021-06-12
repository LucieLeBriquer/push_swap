/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 20:26:26 by lle-briq          #+#    #+#             */
/*   Updated: 2021/06/07 20:26:28 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	multiple_ra(t_stack *stack, int i)
{
	int	j;

	j = -1;
	while (++j < i)
	{
		ft_putstr("ra\n");
		execute_ra(stack);
	}
}

void	multiple_rra(t_stack *stack, int i)
{
	int	j;

	j = -1;
	while (++j < i)
	{
		ft_putstr("rra\n");
		execute_rra(stack);
	}
}

void	multiple_rb(t_stack *stack, int i)
{
	int	j;

	j = -1;
	while (++j < i)
	{
		ft_putstr("rb\n");
		execute_rb(stack);
	}
}

void	multiple_rrb(t_stack *stack, int i)
{
	int	j;

	j = -1;
	while (++j < i)
	{
		ft_putstr("rrb\n");
		execute_rrb(stack);
	}
}
