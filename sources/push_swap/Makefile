CC			= clang -Wall -Wextra -Werror
RM			= rm -rf
NAME		= ../../push_swap
NAME_SHORT	= push_swap

INCS_DIR	= ../../includes/
MAIN_INC	= -I$(INCS_DIR)

LIB_DIR		= ../../libft/
LIB_INC		= -I$(LIB_DIR)includes/
LIB_NAME	= $(LIB_DIR)libft.a

INCS		= $(addprefix $(INCS_DIR), push_swap.h)

SRCS		= main.c \
			  insert.c \
			  isomorphism.c \
			  multiple.c \
			  rev_insert.c \
			  small.c

SRCS_UTILS	= $(addprefix ../utils/, \
			  check.c \
			  print.c \
			  op_push.c \
			  op_reverse.c \
			  op_rotate.c \
			  op_swap.c \
			  stack.c)
 
OBJS		= $(SRCS:.c=.o)
OBJS_UTILS	= $(SRCS_UTILS:.c=.o)

_COLOR		= \033[32m
_BOLDCOLOR	= \033[32;1m
_RESET		= \033[0m
_CLEAR		= \033[0K\r\c
_OK			= [\033[32mOK\033[0m]
_CL			= [\033[33mOK\033[0m]

%.o			: %.c
			@echo "[..] $(NAME_SHORT)... compiling $*.c\r\c"
			@$(CC) $(MAIN_INC) $(LIB_INC) -c $< -o $@
			@echo "$(_CLEAR)"

all			: _libft $(NAME)

$(NAME)		: $(OBJS) $(OBJS_UTILS) $(INCS)
			@$(CC) $(OBJS_UTILS) $(OBJS) $(LIB_NAME) -L$(LIB_DIR) $(LIB_INC) $(MAIN_INC) -o $(NAME)
			@echo "$(_OK) $(NAME_SHORT) compiled"

clean:
			@$(MAKE) clean --silent -C $(LIB_DIR)
			@$(RM) $(OBJS) $(OBJS_UTILS)
			@echo "$(_CL) Cleaning $(NAME_SHORT) files"

fclean		: clean _libft_cl
			@$(RM) $(NAME)
			@echo "$(_CL) Cleaning $(NAME_SHORT)"

re			: fclean all

_libft		:
			@make --silent -C $(LIB_DIR)

_libft_cl	:
			@$(RM) ../../libft/libft.a
			@echo "$(_CL) Cleaning libft.a"

.PHONY		: all clean fclean re _libft _libft_cl
