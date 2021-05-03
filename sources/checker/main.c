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

int	main(int argc, char **argv)
{
	if (check_args(argc, argv))
		ft_putstr("Error\n");
	return (0);
}
