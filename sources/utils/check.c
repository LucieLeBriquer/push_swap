/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 17:15:27 by lle-briq          #+#    #+#             */
/*   Updated: 2021/06/13 22:32:41 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	too_big(int sg, char *str)
{
	if (ft_strlen(str) < 10)
		return (0);
	if (ft_strlen(str) > 10)
		return (1);
	if (sg == 1 && ft_strcmp(str, "2147483647") > 0)
		return (1);
	if (sg == -1 && ft_strcmp(str, "2147483648") > 0)
		return (1);
	return (0);
}

static int	check_one(char *str)
{
	int	i;
	int	sg;

	i = 0;
	sg = 1 - 2 * (str[i] == '-');
	if (str[i] && (str[i] == '+' || str[i] == '-'))
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) || too_big(sg, str + i))
			return (1);
		i++;
	}
	return (0);
}

int	free_split(char **split)
{
	int	i;

	if (split)
	{
		i = 0;
		while (split[i])
		{
			free(split[i]);
			i++;
		}
		free(split);
	}
	return (1);
}

int	check_args(int argc, char **argv, int *tot_size)
{
	int		i;
	int		j;
	char	**split;

	i = 1;
	while (i < argc)
	{
		split = ft_splitchar(argv[i], ' ');
		if (!split)
			return (1);
		j = 0;
		while (split[j])
		{
			if (check_one(split[j]))
				return (free_split(split));
			j++;
		}
		free_split(split);
		*tot_size += j;
		i++;
	}
	return (0);
}
