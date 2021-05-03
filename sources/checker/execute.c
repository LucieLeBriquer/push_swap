/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:52:38 by lle-briq          #+#    #+#             */
/*   Updated: 2021/05/03 16:44:54 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_ope(int op, t_stack *stack)
{
	t_ope	operation[11];

	operation[SA] = &execute_sa;
	operation[SB] = &execute_sb;
	operation[SS] = &execute_ss;
	operation[PA] = &execute_pa;
	operation[PB] = &execute_pb;
	operation[RA] = &execute_ra;
	operation[RB] = &execute_rb;
	operation[RR] = &execute_rr;
	operation[RRA] = &execute_rra;
	operation[RRB] = &execute_rrb;
	operation[RRR] = &execute_rrr;
	operation[op](stack);
}

int	execute_instructions(t_stack *stack)
{
	char	*line;
	int		op;

	(void)stack;
	while (get_next_line(0, &line))
	{
		op = is_instruction(line);
		if (op >= 0)
		{
			execute_ope(op, stack);
			print_stack(*stack);
		}
	}
	return (0);
}
