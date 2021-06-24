/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:48:50 by lle-briq          #+#    #+#             */
/*   Updated: 2021/06/24 13:00:38 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_one(void *content)
{
	(void)content;
	return ;
}

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
		if (stack->moves)
			ft_lstclear(&(stack->moves), &free_one);
		free(stack);
	}
	return (NULL);
}

static void	fill_stack_aux(t_stack *stack, char **split, int *l)
{
	int	k;

	k = 0;
	while (split[k])
	{
		stack->a[*l] = ft_atoi(split[k]);
		(*l)++;
		k++;
	}
}

static int	fill_stack(t_stack *stack, char **argv, int argc)
{
	int		i;
	int		j;
	int		l;
	char	**split;

	i = 0;
	l = 0;
	while (++i < argc)
	{
		split = ft_splitchar(argv[i], ' ');
		if (!split)
			return (1);
		fill_stack_aux(stack, split, &l);
		j = -1;
		while (++j + 1 < l)
		{
			if (stack->a[l - 1] == stack->a[j])
				return (free_split(split));
		}
		free_split(split);
	}
	return (0);
}

int	init_stack(int argc, char **argv, int tot_size, t_stack *stack)
{
	stack->chunk = NULL;
	stack->moves = NULL;
	stack->size = tot_size;
	stack->n_a = stack->size;
	stack->n_b = 0;
	stack->a = malloc(stack->size * sizeof(int));
	stack->b = malloc(stack->size * sizeof(int));
	stack->copy = malloc(stack->size * sizeof(int));
	if (!stack->a || !stack->b || !stack->copy)
	{
		free_all(stack);
		return (1);
	}
	if (fill_stack(stack, argv, argc))
	{
		free_all(stack);
		return (1);
	}
	return (0);
}
