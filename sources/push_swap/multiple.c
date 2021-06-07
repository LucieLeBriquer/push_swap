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