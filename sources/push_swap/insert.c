#include "push_swap.h"

static void	move_to_bottom(t_stack *stack, int pos)
{
	if (pos <= stack->n_b / 2)
		multiple_rb(stack, pos + 1);
	else
		multiple_rrb(stack, stack->n_b - pos - 1);
}

static void	move_to_top(t_stack *stack, int pos)
{
	if (pos <= stack->n_b / 2)
		multiple_rb(stack, pos);
	else
		multiple_rrb(stack, stack->n_b - pos);
}

static void	move_closest(t_stack *stack, int to_insert, int closest)
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