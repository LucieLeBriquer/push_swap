/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 17:42:28 by lle-briq          #+#    #+#             */
/*   Updated: 2021/06/15 18:15:59 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_move(t_stack *stack, char *move)
{
	ft_lstadd_back(&(stack->moves), ft_lstnew(move));
}

static int	double_rotation1(t_list *moves)
{
	char	*cmd1;
	char	*cmd2;

	cmd1 = (char *)moves->content;
	cmd2 = (char *)moves->next->content;
	if (ft_strcmp(cmd1, "ra\n") == 0 && ft_strcmp(cmd2, "rb\n") == 0)
		return (1);
	if (ft_strcmp(cmd1, "rb\n") == 0 && ft_strcmp(cmd2, "ra\n") == 0)
		return (1);
	return (0);
}

static int	double_rotation2(t_list *moves)
{
	char	*cmd1;
	char	*cmd2;

	cmd1 = (char *)moves->content;
	cmd2 = (char *)moves->next->content;
	if (ft_strcmp(cmd1, "rra\n") == 0 && ft_strcmp(cmd2, "rrb\n") == 0)
		return (1);
	if (ft_strcmp(cmd1, "rrb\n") == 0 && ft_strcmp(cmd2, "rra\n") == 0)
		return (1);
	return (0);
}

static int	useless(t_list *moves)
{
	char	*cmd1;
	char	*cmd2;

	cmd1 = (char *)moves->content;
	cmd2 = (char *)moves->next->content;
	if (ft_strcmp(cmd1, "pa\n") == 0 && ft_strcmp(cmd2, "pb\n") == 0)
		return (1);
	if (ft_strcmp(cmd1, "pb\n") == 0 && ft_strcmp(cmd2, "pa\n") == 0)
		return (1);
	return (0);
}

void	print_reduce_moves(t_stack stack)
{
	t_list	*moves;
	int		skip;

	moves = stack.moves;
	while (moves && moves->next)
	{
		skip = 1;
		if (double_rotation1(moves))
			ft_putstr("rr\n");
		else if (double_rotation2(moves))
			ft_putstr("rrr\n");
		else if (useless(moves))
			;
		else
		{
			skip = 0;
			ft_putstr((char *)moves->content);
		}
		moves = moves->next;
		if (skip && moves)
			moves = moves->next;
	}
	if (moves)
		ft_putstr((char *)moves->content);
}
