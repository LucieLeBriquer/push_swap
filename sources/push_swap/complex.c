/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 18:56:05 by lle-briq          #+#    #+#             */
/*   Updated: 2021/06/15 17:50:57 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_and_maj(t_stack *stack, int *min, int *max)
{
	add_move(stack, "pa\n");
	execute_pa(stack);
	if (stack->a[0] == *min)
	{
		add_move(stack, "ra\n");
		execute_ra(stack);
		(*min)++;
	}
	else
		(*max)--;
}

static int	is_min_or_max(int number, int min, int max)
{
	return (number == min || number == max);
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
			if (is_min_or_max(stack->b[i], min, max))
			{
				multiple_rb(stack, i);
				push_and_maj(stack, &min, &max);
				break ;
			}
			else if (is_min_or_max(stack->b[stack->n_b - i - 1], min, max))
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
			add_move(stack, "ra\n");
			execute_ra(stack);
		}
	}
}
