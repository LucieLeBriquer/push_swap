/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 18:56:05 by lle-briq          #+#    #+#             */
/*   Updated: 2021/06/15 17:51:05 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	define_chunks(t_stack *stack)
{
	int	i;
	int	step;

	stack->chunk = malloc((stack->nb_chunk + 1) * sizeof(int));
	if (!stack->chunk)
		return (0);
	i = -1;
	step = stack->size / stack->nb_chunk;
	while (++i < stack->nb_chunk)
		stack->chunk[i] = i * step;
	stack->chunk[stack->nb_chunk] = stack->size;
	return (1);
}

int	is_in_chunk(t_stack stack, int c, int number)
{
	return (stack.chunk[c] <= number && number < stack.chunk[c + 1]);
}

static void	push_and_rev(t_stack *stack, int c)
{
	int	mediane;

	mediane = (stack->chunk[c + 1] + stack->chunk[c]) / 2;
	add_move(stack, "pb\n");
	execute_pb(stack);
	if (stack->b[0] > mediane)
	{
		add_move(stack, "rb\n");
		execute_rb(stack);
	}
}

void	push_chunk_on_b(t_stack *stack, int c)
{
	int	i;

	while (stack->n_b < stack->chunk[c + 1] - stack->chunk[c])
	{
		i = -1;
		while (++i < stack->n_a / 2 + 1)
		{
			if (is_in_chunk(*stack, c, stack->a[i]))
			{
				multiple_ra(stack, i);
				break ;
			}
			else if (is_in_chunk(*stack, c, stack->a[stack->n_a - i - 1]))
			{
				multiple_rra(stack, i + 1);
				break ;
			}
		}
		push_and_rev(stack, c);
	}
}

void	put_on_bot_smallest_sorted(t_stack *stack, int c)
{
	int	i;

	if (c == 0)
		return ;
	i = -1;
	while (++i < stack->n_a / 2 + 1)
	{
		if (stack->a[i] == stack->chunk[c] - 1)
		{
			multiple_ra(stack, i + 1);
			return ;
		}
		else if (stack->a[stack->n_a - i - 1] == stack->chunk[c] - 1)
		{
			multiple_rra(stack, i);
			return ;
		}
	}
}
