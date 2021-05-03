#include "push_swap.h"

int	check_one(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (check_one(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

/*
** check si plus grand qu'un entier
*/

int	is_instruction(char *str)
{
	if (ft_strcmp(str, "sa") == 0)
		return (SA);
	if (ft_strcmp(str, "sb") == 0)
		return (SB);
	if (ft_strcmp(str, "ss") == 0)
		return (SS);
	if (ft_strcmp(str, "pa") == 0)
		return (PA);
	if (ft_strcmp(str, "pb") == 0)
		return (PB);
	if (ft_strcmp(str, "ra") == 0)
		return (RA);
	if (ft_strcmp(str, "rb") == 0)
		return (RB);
	if (ft_strcmp(str, "rr") == 0)
		return (RR);
	if (ft_strcmp(str, "rra") == 0)
		return (RRA);
	if (ft_strcmp(str, "rrb") == 0)
		return (RRB);
	if (ft_strcmp(str, "rrr") == 0)
		return (RRR);
	return (-1);
}

void	check_sorted(t_stack stack)
{
	int	i;

	if (stack.n_b != 0)
	{
		ft_putstr("KO!\n");
		return ;
	}
	i = 0;
	while (i < stack.n_a - 1)
	{
		if (stack.a[i] > stack.a[i + 1])
		{
			ft_putstr("KO!\n");
			return ;
		}
		i++;
	}
	ft_putstr("OK!\n");
}

int		duplicate(t_stack stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack.n_a)
	{
		j = 0;
		while (j < i)
		{
			if (stack.a[i] == stack.a[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
