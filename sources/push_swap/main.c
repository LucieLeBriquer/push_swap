/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 18:00:11 by lle-briq          #+#    #+#             */
/*   Updated: 2021/05/04 18:04:47 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	fill_numbers(int *numbers, int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		numbers[i - 1] = ft_atoi(argv[i]);
		while (j < i - 1)
		{
			if (numbers[i - 1] == numbers[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		*numbers;

	if (argc == 1)
		return (0);
	if (check_args(argc, argv))
		return (print_error("Error\n"));
	numbers = malloc(argc * sizeof(int));
	if (!numbers)
		return (print_error("Allocation issues\n"));
	if (fill_numbers(numbers, argc, argv))
	{
		free(numbers);
		return (print_error("Error\n"));
	}
	free(numbers);
	return (0);
}
