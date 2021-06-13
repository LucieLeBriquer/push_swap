/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:48:50 by lle-briq          #+#    #+#             */
/*   Updated: 2021/06/13 22:52:16 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*free_all(t_stack *stack)
{
	if (stack)
	{
		if (stack->a)
			free(stack->a);
		if (stack->b)
			free(stack->b);
		if (stack->copy)
			free(stack->copy);
		if (stack->chunk)
			free(stack->chunk);
		free(stack);
	}
	return (NULL);
}

static int	fill_stack(t_stack *stack, char **argv, int argc)
{
	int		i;
	int		j;
	int		k;
	int		l;
	char	**split;

	i = 0;
	l = 0;
	while (++i < argc)
	{
		split = ft_splitchar(argv[i], ' ');
		if (!split)
			return (1);
		k = 0;
		while (split[k])
		{
			stack->a[l] = ft_atoi(split[k]);
			l++;
			k++;
		}
		j = -1;
		while (++j + 1 < l)
		{
			if (stack->a[l - 1] == stack->a[j])
				return (free_split(split));
		}
		free_split(split);
	}
	stack->n_a = stack->size;
	stack->n_b = 0;
	return (0);
}

t_stack	*init_stack(int argc, char **argv, int tot_size)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->size = tot_size;
	stack->a = malloc(stack->size * sizeof(int));
	stack->b = malloc(stack->size * sizeof(int));
	stack->copy = malloc(stack->size * sizeof(int));
	stack->chunk = NULL;
	if (!stack->a || !stack->b || !stack->copy)
		return (free_all(stack));
	if (fill_stack(stack, argv, argc))
		return (free_all(stack));
	return (stack);
}
