/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:37:32 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/20 16:19:30 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# define MIN_INT -2147483648
# define MAX_INT 2147483647

typedef struct s_stack_node
{
	int					content;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}				t_stack_node;

typedef struct s_stack
{
	char			name;
	t_stack_node	*top;
	t_stack_node	*begin;
	int				size;
}				t_stack;

void	check_start_arguments(const int argc, const char **argv);
t_stack	*stack_create(char name);
void	stack_destroy(t_stack *stack_ref);
void	add_node_to_stack(t_stack *stack_ref, int content);
void	del_node_of_stack(t_stack *stack_ref);
void	stack_swap(t_stack *stack_ref);
void	stack_rotate(t_stack *stack_ref);
void	stack_reverse_rotate(t_stack *stack_ref);
void	stack_push(t_stack *stack_src_ref, t_stack *stack_dst_ref);
void	init(t_stack *stack_ref, int argc, char **argv);
int		stack_is_sorted(t_stack *stack_ref);
void	stack_sort(t_stack *stack_a_ref, t_stack *stack_b_ref);
int		find_bigger(t_stack *stack_ref);
int		find_smaller(t_stack *stack_ref);

#endif
