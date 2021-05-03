#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/includes/libftfull.h"

int	check_args(int argc, char **argv);

typedef struct	s_stack
{
	int	*a;
	int	*b;
	int	size;
	int	n_b;
	int	n_a;
}				t_stack;

#endif
