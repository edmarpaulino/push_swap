# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 11:45:05 by edpaulin          #+#    #+#              #
#    Updated: 2021/11/30 16:06:06 by edpaulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap
BONUS_NAME		=	

AUX_DIR			=	aux
AUX_FILES		=	check_start_arguments.c
AUX_PATH		=	$(addprefix $(AUX_DIR)/, $(AUX_FILES))

STK_DIR			=	stk
STK_FILES		=	stack_create.c \
					stack_destroy.c \
					node_create.c \
					add_node_to_stack.c \
					stack_swap.c \
					stack_push.c \
					stack_rotate.c \
					stack_reverse_rotate.c \
					stack_is_sorted_ascending.c \
					stack_is_sorted_descending.c
STK_PATH		=	$(addprefix $(STK_DIR)/, $(STK_FILES))

SRC_DIR			=	./src
SRC_FILES		=	main.c \
					unique_operations.c \
					double_operations.c \
					init.c \
					data_destroy.c \
					push_swap.c \
					sort_stack_size_two.c \
					find_smaller.c \
					find_bigger.c \
					sort_stack_size_three.c \
					get_direction.c \
					sort_stack_size_four.c \
					get_pivot.c \
					sort_stack_size_two_reverse.c \
					sort_stack_size_five.c \
					sort_stack_size_three_reverse.c \
					sort_stack_size_six.c \
					get_hold.c \
					send_hold.c \
					send_chunk.c \
					send_back_to_a.c \
					sort_stack_size_up_to_hundred.c \
					sort_stack_greater_than_hundred.c \
					$(AUX_PATH) \
					$(STK_PATH)

BONUS_DIR		=	
BONUS_FILES		=	

OBJ_DIR			=	./obj
OBJ_FILES		=	$(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
OBJ_BONUS_FILES	=	$(addprefix $(OBJ_DIR)/, $(BONUS_FILES:.c=.o))

LIBFT_DIR		=	./libft
LIBFT			=	libft.a
LIBFT_INC		=	$(LIBFT_DIR)/inc
LIBFT_PATH		=	$(addprefix $(LIBFT_DIR)/, $(LIBFT))

#	REMOVE LATER
ERROR_FLAGS		=	-g3 -std=c11 -ggdb3

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror $(ERROR_FLAGS)
INC				=	-I ./inc -I $(LIBFT_INC)

MKDIR			=	mkdir -p $(@D)
AR				=	ar -rcs
RM				=	rm -rf

.DEFAULT_GOAL	=	all

all:				$(NAME)

$(OBJ_DIR)/%.o:		$(SRC_DIR)/%.c
	$(MKDIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME):			$(OBJ_FILES) $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(INC) $(OBJ_FILES) $(LIBFT_PATH) -o $(NAME)

bonus:				$(OBJ_BONUS_FILES) $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(INC) $(OBJ_BONUS_FILES) $(LIBFT_PATH) -o $(BONUS_NAME)

$(LIBFT_PATH):
	make all -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)

fclean:				clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)

re:					fclean all

rebonus:			fclean bonus 

.PHONY:				all bonus clean fclean re rebonus
