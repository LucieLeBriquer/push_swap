/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 18:00:11 by lle-briq          #+#    #+#             */
/*   Updated: 2021/05/06 14:44:17 by lle-briq         ###   ########.fr       */
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

void	move_to_bottom(t_stack *stack, int pos)
{
	if (pos <= stack->n_b / 2)
		multiple_rb(stack, pos + 1);
	else
		multiple_rrb(stack, stack->n_b - pos - 1);
}

void	move_to_top(t_stack *stack, int pos)
{
	if (pos <= stack->n_b / 2)
		multiple_rb(stack, pos);
	else
		multiple_rrb(stack, stack->n_b - pos);
}

void	move_closest(t_stack *stack, int to_insert, int closest)
{
	if (stack->b[closest] > to_insert)
		move_to_bottom(stack, closest);
	else
		move_to_top(stack, closest);
}

void	insert_sort(t_stack *stack)
{
	int	to_insert;
	int	i;
	int	dist;
	int	closest;

	to_insert = stack->a[0];
	if (stack->n_b == 0)
	{
		ft_putstr("pb\n");
		return (execute_pb(stack));
	}
	dist = abs(to_insert - stack->b[0]);
	closest = 0;
	i = -1;
	while (++i < stack->n_b)
	{
		if (abs(to_insert - stack->b[i]) < dist)
		{
			dist = abs(to_insert - stack->b[i]);
			closest = i;
		}
	}
	move_closest(stack, to_insert, closest);
	ft_putstr("pb\n");
	execute_pb(stack);
}

void	push_all(t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < stack->n_b / 2 + 1)
	{
		if (stack->b[i] + 1 == stack->size)
		{
			multiple_rb(stack, i);
			break;
		}
		else if (stack->b[stack->n_b - i - 1] + 1 == stack->size)
		{
			multiple_rrb(stack, i + 1);
			break;
		}
	}
	while (stack->n_b > 0)
	{
		execute_pa(stack);
		ft_putstr("pa\n");
	}
}

void	generate_size3(t_stack *stack)
{
	if (stack->a[2] > stack->a[0] && stack->a[0] > stack->a[1])
	{
		ft_putstr("sa\n");
		return (execute_sa(stack));
	}
	if (stack->a[0] > stack->a[1] && stack->a[1] > stack->a[2])
	{
		ft_putstr("sa\nrra\n");
		execute_sa(stack);
		return (execute_rra(stack));
	}
	if (stack->a[0] > stack->a[2] && stack->a[2] > stack->a[1])
	{
		ft_putstr("ra\n");
		return (execute_ra(stack));
	}
	if (stack->a[1] > stack->a[2] && stack->a[2] > stack->a[0])
	{
		ft_putstr("sa\nra\n");
		execute_sa(stack);
		return (execute_ra(stack));
	}
	if (stack->a[1] > stack->a[0] && stack->a[0] > stack->a[2])
	{
		ft_putstr("rra\n");
		return (execute_rra(stack));
	}
}

void	rev_move_to_bottom(t_stack *stack, int pos)
{
	if (pos <= stack->n_a / 2)
		multiple_ra(stack, pos + 1);
	else
		multiple_rra(stack, stack->n_a - pos - 1);
}

void	rev_move_to_top(t_stack *stack, int pos)
{
	if (pos <= stack->n_a / 2)
		multiple_ra(stack, pos);
	else
		multiple_rra(stack, stack->n_a - pos);
}

void	rev_move_closest(t_stack *stack, int to_insert, int closest)
{
	if (stack->a[closest] > to_insert)
		rev_move_to_top(stack, closest);
	else
		rev_move_to_bottom(stack, closest);
}

void	rev_insert_sort(t_stack *stack)
{
	int	to_insert;
	int	i;
	int	dist;
	int	closest;

	to_insert = stack->b[0];
	dist = abs(to_insert - stack->a[0]);
	closest = 0;
	i = -1;
	while (++i < stack->n_a)
	{
		if (abs(to_insert - stack->a[i]) < dist)
		{
			dist = abs(to_insert - stack->a[i]);
			closest = i;
		}
	}
	rev_move_closest(stack, to_insert, closest);
	ft_putstr("pa\n");
	execute_pa(stack);
}

void	generate_size5(t_stack *stack)
{
	int	pos;

	while (stack->n_a > 3)
	{
		ft_putstr("pb\n");
		execute_pb(stack);
	}
	generate_size3(stack);
	rev_insert_sort(stack);
	if (stack->n_b > 0)
		rev_insert_sort(stack);
	pos = -1;
	while (++pos < stack->n_a && stack->a[pos] > 0)
		;
	rev_move_to_top(stack, pos);
}

void	generate_simple(t_stack *stack)
{
	if (stack->size == 1)
		return ;
	if (stack->size == 2)
	{
		if (stack->a[0] < stack->a[1])
			return ;
		ft_putstr("sa\n");
		execute_sa(stack);
		return ;
	}
	if (stack->size == 3)
		return (generate_size3(stack));
	generate_size5(stack);
}

void	generate_code(t_stack *stack)
{
	int	c;
	int	i;

	c = 0;
	if (stack->size <= 5)
		return (generate_simple(stack));
	while (c < stack->nb_chunk)
	{
		while (stack->n_b != stack->chunk[c])
		{
			i = -1;
			while (++i < stack->n_a / 2 + 1)
			{
				if (stack->a[i] < stack->chunk[c])
				{
					multiple_ra(stack, i);
					insert_sort(stack);
					break;
				}
				else if (stack->a[stack->n_a - i - 1] < stack->chunk[c])
				{
					multiple_rra(stack, i + 1);
					insert_sort(stack);
					break;
				}
			}
			print_stack(*stack);
		}
		c++;
	}
	push_all(stack);
}

int	is_already_sorted(t_stack stack)
{
	int	i;

	i = 0;
	while (i < stack.n_a - 1)
	{
		if (stack.a[i] > stack.a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc == 1)
		return (0);
	if (check_args(argc, argv))
		return (print_error("Error\n"));
	stack = init_stack(argc, argv);
	if (!stack)
		return (print_error("Error\n"));
	isomorphism(stack);
	if (is_already_sorted(*stack))
		return (0);
	generate_code(stack);
	free_all(stack);
	return (0);
}