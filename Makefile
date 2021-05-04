CC			= clang -Wall -Wextra -Werror
RM			= rm -rf

CHECK		= checker 
PUSH		= push_swap

INCS_DIR	= ./includes/
MAIN_INC	= -I$(INCS_DIR)

LIB_DIR		= ./libft/
LIB_INC		= -I$(LIB_DIR)includes/
LIB_NAME	= $(LIB_DIR)libft.a

INCS		= $(addprefix $(INCS_DIR), push_swap.h)

SRCS_CH		=  $(addprefix sources/checker/, main.c check.c execute.c operations.c useful.c)
SRCS_PS		=  $(addprefix sources/push_swap/, main.c)
 
OBJS_CH		= $(SRCS_CH:.c=.o)
OBJS_PS		= $(SRCS_PS:.c=.o)

%.o			: %.c
			@$(CC) $(MAIN_INC) $(LIB_INC) -c $< -o $@

all			: $(CHECK) $(PUSH)

$(CHECK)	: $(OBJS_CH) $(INCS)
			@make --silent -C $(LIB_DIR)
			@$(CC) $(OBJS_CH) $(LIB_NAME) -L$(LIB_DIR) $(LIB_INC) $(MAIN_INC) -o $(CHECK)
			@echo "checker compiled"

$(PUSH)		: $(OBJS_PS) $(INCS)
			@make --silent -C $(LIB_DIR)
			@$(CC) $(OBJS_PS) $(LIB_NAME) -L$(LIB_DIR) $(LIB_INC) $(MAIN_INC) -o $(PUSH)
			@echo "push_swap compiled"

clean:
			@$(MAKE) clean --silent -C $(LIB_DIR)
			@$(RM) $(OBJS_PS) $(OBJS_CH)

fclean		: clean
			@$(MAKE) fclean --silent -C $(LIB_DIR)
			@$(RM) $(PUSH) $(CHECK)

re			: fclean all

.PHONY		: all clean fclean re
