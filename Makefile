# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Gkatounk <gkatounk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/17 14:59:41 by Gkatounk          #+#    #+#              #
#    Updated: 2021/12/17 14:59:42 by Gkatounk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER   = checker

PUSH_SWAP   = push_swap

CC	     = gcc $(FLAGS)

FLAGS    = #-Wall -Werror -Wextra -fsanitize=address

CHECKER_SRC = src/checker.c src/shared/ft_init.c \
							src/shared/checker_utils.c \
							src/shared/checker_utils1.c \
							src/shared/ft_split.c \
							src/shared/ft_push_swap_utils.c \
							src/shared/ft_push_swap_utils1.c \
							src/shared/ft_free.c \
							src/shared/errors.c \
							src/shared/stack_utils.c \
							src/shared/stack_utils1.c \
							src/shared/stack_utils2.c \
							src/shared/operations.c \
							src/shared/operations1.c \
							src/shared/ft_sort_utils.c\
							src/shared/ft_sort_min.c

PUSH_SWAP_SRC = src/push_swap.c src/shared/ft_init.c \
							src/shared/checker_utils.c \
							src/shared/checker_utils1.c \
							src/shared/ft_split.c \
							src/shared/ft_push_swap_utils.c \
							src/shared/ft_push_swap_utils1.c \
							src/shared/ft_free.c \
							src/shared/errors.c \
							src/shared/stack_utils.c \
							src/shared/stack_utils1.c \
							src/shared/stack_utils2.c \
							src/shared/operations.c \
							src/shared/operations1.c \
							src/shared/ft_sort_utils.c \
							src/shared/ft_sort_utils1.c \
							src/shared/ft_sort_min.c \
							src/shared/ft_sort.c \
							src/shared/ft_sort_big.c


CHECKER_SRC_OBJ	= $(CHECKER_SRC:.c=.o)

PUSH_SWAP_SRC_OBJ	= $(PUSH_SWAP_SRC:.c=.o)

all : $(PUSH_SWAP) $(CHECKER)
$(PUSH_SWAP) : ${PUSH_SWAP_SRC_OBJ}
	${CC} $(CFLAGS) -o $(PUSH_SWAP) $(PUSH_SWAP_SRC_OBJ)
$(CHECKER) : ${CHECKER_SRC_OBJ}
	${CC} $(CFLAGS) -o $(CHECKER) $(CHECKER_SRC_OBJ)
clean :
	@rm -rf ${PUSH_SWAP_SRC_OBJ} ${CHECKER_SRC_OBJ}

fclean: clean
	@rm -rf $(CHECKER) $(PUSH_SWAP)

re: fclean all

.PHONY : bonus all clean fclean re