#include "push_swap.h"

static void	rev_move_to_bottom(t_stack *stack, int pos)
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

static void	rev_move_closest(t_stack *stack, int to_insert, int closest)
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