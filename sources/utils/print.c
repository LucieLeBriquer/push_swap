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

void	print_stack(t_stack stack)
{
	int	i;

	i = 0;
	ft_putstr("-----------------------\n");
	while (i < stack.n_a || i < stack.n_b)
	{
		if (i < stack.n_a && i < stack.n_b)
			ft_printf("%11d %11d\n", stack.a[i], stack.b[i]);
		else if (i < stack.n_a)
			ft_printf("%11d\n", stack.a[i]);
		else
			ft_printf("%s%11d\n", "            ", stack.b[i]);
		i++;
	}
	ft_putstr("___________ ");
	ft_putstr("___________\n");
	ft_putstr("     a           b\n");
	ft_putstr("-----------------------\n\n");
}
