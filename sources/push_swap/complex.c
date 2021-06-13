/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 18:56:05 by lle-briq          #+#    #+#             */
/*   Updated: 2021/06/13 18:56:53 by lle-briq         ###   ########.fr       */
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

int		is_in_chunk(t_stack stack, int c, int number)
{
	return (stack.chunk[c] <= number && number < stack.chunk[c + 1]);
}

void	push_chunk_on_b(t_stack *stack, int c)
{
	int	mediane;
	int	i;

	mediane = (stack->chunk[c + 1] + stack->chunk[c]) / 2;
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
		ft_putstr("pb\n");
		execute_pb(stack);
		if (stack->b[0] > mediane)
		{
			ft_putstr("rb\n");
			execute_rb(stack);
		}
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

void	push_and_maj(t_stack *stack, int *min, int *max)
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

void	push_sorted_on_a(t_stack *stack, int c)
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