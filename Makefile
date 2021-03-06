# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 11:45:05 by edpaulin          #+#    #+#              #
#    Updated: 2021/12/09 14:42:45 by edpaulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap
BONUS_NAME		=	checker

AUX_DIR			=	aux
AUX_FILES		=	check_start_arguments.c \
					init.c \
					data_destroy.c \
					find_smaller.c \
					find_bigger.c \
					get_direction.c \
					get_pivot.c \
					has_at_least_one_digit.c \
					clear_splits.c \
					get_splits.c
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
					stack_is_sorted_descending.c \
					add_node_begin.c
STK_PATH		=	$(addprefix $(STK_DIR)/, $(STK_FILES))

SORT_DIR		=	sort
SORT_FILES		=	unique_operations.c \
					double_operations.c \
					sort_parser.c \
					sort_stack_size_two.c \
					sort_stack_size_three.c \
					sort_stack_size_four.c \
					sort_stack_size_two_reverse.c \
					sort_stack_size_five.c \
					sort_stack_size_three_reverse.c \
					sort_stack_size_six.c \
					stack_a_complex_sort.c \
					stack_b_complex_sort.c \
					sort_top_a.c \
					sort_top_b.c \
					sort_descending.c
SORT_PATH		=	$(addprefix $(SORT_DIR)/, $(SORT_FILES))

SRC_DIR			=	./src
SRC_FILES		=	push_swap.c \
					$(AUX_PATH) \
					$(SORT_PATH) \
					$(STK_PATH)

BONUS_DIR		=	./src
BONUS_FILES		=	checker.c \
					$(AUX_PATH) \
					$(STK_PATH)

OBJ_DIR			=	./obj
OBJ_FILES		=	$(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
OBJ_BONUS_FILES	=	$(addprefix $(OBJ_DIR)/, $(BONUS_FILES:.c=.o))

LIBFT_DIR		=	./libft
LIBFT			=	libft.a
LIBFT_INC		=	$(LIBFT_DIR)/inc
LIBFT_PATH		=	$(addprefix $(LIBFT_DIR)/, $(LIBFT))

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
INC				=	-I ./inc -I $(LIBFT_INC)

MKDIR			=	mkdir -p $(@D)
AR				=	ar -rcs
RM				=	rm -rf

.DEFAULT_GOAL	=	all

all:				$(NAME)

bonus:				$(BONUS_NAME)

$(OBJ_DIR)/%.o:		$(SRC_DIR)/%.c
	$(MKDIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME):			$(OBJ_FILES) $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(INC) $(OBJ_FILES) $(LIBFT_PATH) -o $(NAME)

$(BONUS_NAME):		$(OBJ_BONUS_FILES) $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(INC) $(OBJ_BONUS_FILES) $(LIBFT_PATH) -o $(BONUS_NAME)
	
	

$(LIBFT_PATH):
	make all -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)

fclean:				clean
	$(RM) $(NAME) $(BONUS_NAME)
	make fclean -C $(LIBFT_DIR)

re:					fclean all

rebonus:			fclean bonus 

.PHONY:				all bonus clean fclean re rebonus
