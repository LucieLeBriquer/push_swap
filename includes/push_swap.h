/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 23:20:50 by lle-briq          #+#    #+#             */
/*   Updated: 2021/05/06 14:43:26 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/includes/libftfull.h"

/*
** structures
*/

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	*iso;
	int *rev_iso;
	int	*copy;
	int	size;
	int	n_b;
	int	n_a;
	int	chunk[4];
}		t_stack;

typedef void	(*t_ope)(t_stack *stack);

enum	{SA, SB, SS, PA, PB, RA, RB, RR, RRA, RRB, RRR};

/*
** general
*/

int		check_args(int argc, char **argv);
int		execute_instructions(t_stack *stack);
int		is_instruction(char *str);
void	print_stack(t_stack stack);
void	check_sorted(t_stack stack);
int		duplicate(t_stack stack);
int		print_error(char *str);
void	print_stack(t_stack stack);
t_stack	*init_stack(int argc, char **argv);
void	free_all(t_stack *stack);

/*
** push swap
*/

void    isomorphism(t_stack *stack);

/*
** basic operations
*/

void	execute_sa(t_stack *stack);
void	execute_sb(t_stack *stack);
void	execute_ss(t_stack *stack);
void	execute_pa(t_stack *stack);
void	execute_pb(t_stack *stack);
void	execute_ra(t_stack *stack);
void	execute_rb(t_stack *stack);
void	execute_rr(t_stack *stack);
void	execute_rra(t_stack *stack);
void	execute_rrb(t_stack *stack);
void	execute_rrr(t_stack *stack);

#endif
