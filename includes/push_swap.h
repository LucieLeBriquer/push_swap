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

int	check_args(int argc, char **argv);
int	execute_instructions(t_stack *stack);
int	is_instruction(char *str);

enum	{SA, SB, SS, PA, PB, RA, RB, RR, RRA, RRB, RRR};

#endif
