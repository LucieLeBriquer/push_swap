#include "push_swap.h"

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