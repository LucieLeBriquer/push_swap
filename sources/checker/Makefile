CC			= clang -Wall -Wextra -Werror
RM			= rm -rf
NAME		= ../../checker
NAME_SHORT	= checker

INCS_DIR	= ../../includes/
MAIN_INC	= -I$(INCS_DIR)
INCS		= $(shell find $(INCS_DIR) -type f -name "*.h")

LIB_DIR		= ../../libft/
LIB_INC		= -I$(LIB_DIR)includes/
LIB_NAME	= $(LIB_DIR)libft.a

SRCS_DIR 	= .
SRCS		= $(notdir $(shell find $(SRC_DIR) -type f -name "*.c"))

UTILS_DIR	= ../utils
UTILS		= $(addprefix $(UTILS_DIR)/, $(notdir $(shell find $(UTILS_DIR) -type f -name "*.c")))

OBJS		= $(SRCS:.c=.o)
OBJS_UTILS	= $(UTILS:.c=.o)

_COLOR		= \033[32m
_BOLDCOLOR	= \033[32;1m
_RESET		= \033[0m
_CLEAR		= \033[0K\r\c
_OK			= [\033[32mOK\033[0m]

%.o			: %.c
			@echo "[..] $(NAME_SHORT)... compiling $*.c\r\c"
			@$(CC) $(MAIN_INC) $(LIB_INC) -c $< -o $@
			@echo "$(_CLEAR)"

all			: _libft $(NAME)

$(NAME)		: $(OBJS) $(OBJS_UTILS) $(INCS)
			@$(CC) $(OBJS_UTILS) $(OBJS) $(LIB_NAME) -L$(LIB_DIR) $(LIB_INC) $(MAIN_INC) -o $(NAME)
			@echo "$(_OK) $(NAME_SHORT) compiled"

clean		:
			@$(MAKE) clean --silent -C $(LIB_DIR)
			@$(RM) $(OBJS) $(OBJS_UTILS)

fclean		: clean _libft_cl
			@$(RM) $(NAME)

re			: fclean all

norme		:
			@norminette $(SRCS) $(UTILS) $(INCS)

_libft		:
			@make --silent -C $(LIB_DIR)

_libft_cl	:
			@$(RM) $(LIB_NAME)

.PHONY		: all clean fclean re _libft _libft_cl norme
