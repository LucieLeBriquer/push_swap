/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:48:50 by lle-briq          #+#    #+#             */
/*   Updated: 2021/05/06 14:42:45 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_stack *stack)
{
	if (stack->a)
		free(stack->a);
	if (stack->b)
		free(stack->b);
	if (stack->iso)
		free(stack->iso);
	if (stack)
		free(stack);
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
	stack->a = malloc((argc - 1) * sizeof(int));
	stack->b = malloc((argc - 1) * sizeof(int));
	stack->copy = malloc((argc - 1) * sizeof(int));
	if (!stack->a || !stack->b || !stack->copy)
	{
		free_all(stack);
		return (NULL);
	}
	stack->size = argc - 1;
	stack->chunk[0] = stack->size / 2;
	stack->chunk[1] = stack->size / 4;
	stack->chunk[2] = stack->size / 8;
	stack->chunk[3] = stack->size / 16;
	if (fill_stack(stack, argv))
	{
		free_all(stack);
		return (NULL);
	}
	return (stack);
}
