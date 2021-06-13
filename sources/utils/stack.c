/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:48:50 by lle-briq          #+#    #+#             */
/*   Updated: 2021/06/13 20:45:26 by lle-briq         ###   ########.fr       */
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

static int	fill_stack(t_stack *stack, char **argv)
{
	int	i;
	int	j;

	i = -1;
	while (++i < stack->size)
	{
		stack->a[i] = ft_atoi(argv[i + 1]);
		j = -1;
		while (++j < i - 1)
		{
			if (stack->a[i] == stack->a[j])
				return (1);
		}
	}
	stack->n_a = stack->size;
	stack->n_b = 0;
	return (0);
}

t_stack	*init_stack(int argc, char **argv)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->size = argc - 1;
	stack->a = malloc(stack->size * sizeof(int));
	stack->b = malloc(stack->size * sizeof(int));
	stack->copy = malloc(stack->size * sizeof(int));
	stack->chunk = NULL;
	if (!stack->a || !stack->b || !stack->copy)
		return (free_all(stack));
	if (fill_stack(stack, argv))
		return (free_all(stack));
	return (stack);
}
