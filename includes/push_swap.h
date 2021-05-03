#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/includes/libftfull.h"

typedef struct	s_stack
{
	int	*a;
	int	*b;
	int	size;
	int	n_b;
	int	n_a;
}				t_stack;

typedef void (*t_ope)(t_stack *stack);

int		check_args(int argc, char **argv);
int		execute_instructions(t_stack *stack);
int		is_instruction(char *str);
void	print_stack(t_stack stack);

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

enum	{SA, SB, SS, PA, PB, RA, RB, RR, RRA, RRB, RRR};

#endif
