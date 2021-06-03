/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:48:50 by lle-briq          #+#    #+#             */
/*   Updated: 2021/05/04 17:44:55 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_error(char *str)
{
	ft_putstr_fd(str, 2);
	return (0);
}

int	which_chunk(t_stack stack, int i)
{
	if (i >= stack.chunk[0])
		return (-1);
	if (i < stack.chunk[3])
		return (3);
	if (i < stack.chunk[2])
		return (2);
	if (i < stack.chunk[1])
		return (1);
	return (0);
}

char	*chunk_color(t_stack stack, int i)
{
	if (which_chunk(stack, i) == 1)
		return ("\033[31m");
	if (which_chunk(stack, i) == 2)
		return ("\033[32m");
	if (which_chunk(stack, i) == 3)
		return ("\033[33m");
	if (which_chunk(stack, i) == 0)
		return ("\033[34m");
	return ("\033[0m");
}

void	print_stack(t_stack stack)
{
	int	i;

	i = 0;
	ft_putstr("-----------------------\n");
	while (i < stack.n_a || i < stack.n_b)
	{
		if (i < stack.n_a && i < stack.n_b)
			ft_printf("%s%11d %s%11d\n", chunk_color(stack, stack.a[i]), stack.a[i], chunk_color(stack, stack.b[i]), stack.b[i]);
		else if (i < stack.n_a)
			ft_printf("%s%11d\n",  chunk_color(stack, stack.a[i]), stack.a[i]);
		else
			ft_printf("%s%s%11d\n", "            ", chunk_color(stack, stack.b[i]), stack.b[i]);
		i++;
	}
	ft_putstr("\033[0m___________ ");
	ft_putstr("___________\n");
	ft_putstr("     a           b\n");
	ft_putstr("-----------------------\n\n");
}
