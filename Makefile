CH_DIR		= sources/checker/
PS_DIR		= sources/push_swap/
LIBFT_DIR	= libft/

all			:
			@make --silent -C $(PS_DIR)

bonus		:
			@make --silent -C $(CH_DIR)

clean		:
			@make clean --silent -C $(PS_DIR)
			@make clean --silent -C $(CH_DIR)

fclean		:
			@make fclean --silent -C $(PS_DIR)
			@make fclean --silent -C $(CH_DIR)

re			: fclean all

refull		: re bonus

full		: all bonus

norme		:
			@make norme --silent -C $(CH_DIR)
			@make norme --silent -C $(PS_DIR)
			@make norme --silent -C $(LIBFT_DIR)

.PHONY		: all clean fclean re bonus full refull norme