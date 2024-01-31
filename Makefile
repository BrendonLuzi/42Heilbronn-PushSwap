# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/19 16:12:56 by bluzi             #+#    #+#              #
#    Updated: 2023/03/19 21:58:29 by bluzi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= src/push_swap.c			\
				  src/ps_main.c				\
				  src/ps_utils.c			\
				  src/ps_operations.c		\
				  src/ps_lis.c				\
				  src/ps_extra_utils.c		\
				  src/linked_list_utils.c	\
				  src/ps_bblsort.c			\
				  src/ps_bblsort_utils.c	\
				  src/ps_parsing.c			\
				  
BNS_SRCS		= src/ps_checker.c			\
				  src/ps_checker_main.c		\
				  src/linked_list_utils.c	\
				  src/ps_extra_utils.c		\
				  src/ps_operations.c		\
				  src/ps_utils.c			\
				  src/ps_parsing.c			\

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= push_swap
BNS_NAME		= checker

LIBFT			= libft/libft.a
PRINTF			= printf/libftprintf.a

all:			$(NAME)

$(NAME): $(LIBFT) $(PRINTF)
				@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(PRINTF) -o $(NAME)
				@echo Compiling push_swap

$(LIBFT):
				@make all -C libft
				@echo Compiling libft

$(PRINTF):
				@make all -C printf
				@echo Compiling printf

bonus:			all $(LIBFT) $(PRINTF)
				@$(CC) $(CFLAGS) $(BNS_SRCS) $(LIBFT) $(PRINTF) -o $(BNS_NAME)
				@echo Compiling checker

clean:
				@$(RM) $(OBJS) $(BNS_OBJS)
				@make clean -C libft
				@make clean -C printf
				@echo Cleaning objects

fclean:			clean
				@$(RM) $(NAME) $(BNS_NAME)
				@make fclean -C libft
				@make fclean -C printf
				@echo Cleaning executables

re:				fclean $(NAME)

.PHONY:			all clean fclean re