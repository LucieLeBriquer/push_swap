CC			= clang -Wall -Wextra -Werror
RM			= rm -rf

CHECK		= checker 
PUSH		= push_swap

CH_DIR		= sources/checker/
PS_DIR		= sources/push_swap/

all			: $(PUSH)

bonus		: $(CHECK)

$(PUSH)		:
			@make --silent -C $(PS_DIR)

$(CHECK)	: $(PUSH)
			@make --silent -C $(CH_DIR)

clean		:
			@$(MAKE) clean --silent -C $(PS_DIR)
			@$(MAKE) clean --silent -C $(CH_DIR)

fclean		:
			@$(MAKE) fclean --silent -C $(PS_DIR)
			@$(MAKE) fclean --silent -C $(CH_DIR)

re			: fclean all

full		: re bonus

.PHONY		: all clean fclean re bonus full