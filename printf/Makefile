NAME	=	libftprintf.a
SRC		=	ft_printf.c				\
			ft_printf_flags.c		\
			ft_printf_formats.c		\
			ft_printf_printers.c	\
			ft_printf_utilities.c

OBJ			=	$(SRC:%.c=%.o)

CFLAGS			= -Wall -Wextra -Werror

all			:	$(NAME)

$(NAME)		:	$(OBJ)
	@ar rc $(NAME) $(OBJ)

bonus		:	$(OBJ)
	@ar rc $(NAME) $^

$(OBJ)		:	$(SRC)
	@cc $(CFLAGS) -c $^

clean		:
	@rm -f $(OBJ)

fclean		:	clean
	@rm -f $(NAME)

re			:	fclean all

.PHONY:		all clean fclean re