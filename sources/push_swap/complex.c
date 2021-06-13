/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 18:56:05 by lle-briq          #+#    #+#             */
/*   Updated: 2021/06/13 19:01:35 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_and_maj(t_stack *stack, int *min, int *max)
{
	ft_putstr("pa\n");
	execute_pa(stack);
	if (stack->a[0] == *min)
	{
		ft_putstr("ra\n");
		execute_ra(stack);
		(*min)++;
	}
	else
		(*max)--;
}

static void	push_sorted_on_a(t_stack *stack, int c)
{
	int	max;
	int	min;
	int	i;

	max = stack->chunk[c + 1] - 1;
	min = stack->chunk[c];
	while (stack->n_b > 0)
	{
		i = -1;
		while (++i < stack->n_b / 2 + 1)
		{
			if (stack->b[i] == min || stack->b[i] == max)
			{
				multiple_rb(stack, i);
				push_and_maj(stack, &min, &max);
				break ;
			}
			else if (stack->b[stack->n_b - i - 1] == min || stack->b[stack->n_b - i - 1] == max)
			{
				multiple_rrb(stack, i + 1);
				push_and_maj(stack, &min, &max);
				break ;
			}
		}
	}
}

void	generate_complex(t_stack *stack)
{
	int	c;

	c = -1;
	while (++c < stack->nb_chunk)
	{
		push_chunk_on_b(stack, c);
		put_on_bot_smallest_sorted(stack, c);
		push_sorted_on_a(stack, c);
		while (is_in_chunk(*stack, c, stack->a[0]))
		{
			ft_putstr("ra\n");
			execute_ra(stack);
		}
	}
}