/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 17:12:19 by lle-briq          #+#    #+#             */
/*   Updated: 2021/06/25 16:19:26 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		ft_putstr("KO\n");
		return ;
	}
	i = 0;
	while (i < stack.n_a - 1)
	{
		if (stack.a[i] > stack.a[i + 1])
		{
			ft_putstr("KO\n");
			return ;
		}
		i++;
	}
	ft_putstr("OK\n");
}
