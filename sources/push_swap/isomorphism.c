/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isomorphism.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 20:24:12 by lle-briq          #+#    #+#             */
/*   Updated: 2021/06/24 22:35:58 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	isomorphism(t_stack *stack)
{
	int	i;
	int	j;
	int	above;

	i = -1;
	while (++i < stack->size)
		stack->copy[i] = stack->a[i];
	i = -1;
	while (++i < stack->size)
	{
		above = 0;
		j = -1;
		while (++j < stack->size)
		{
			if (stack->copy[j] < stack->copy[i])
				above++;
		}
		stack->a[i] = above;
	}
}
