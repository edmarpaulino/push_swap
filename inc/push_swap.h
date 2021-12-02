/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:37:32 by edpaulin          #+#    #+#             */
/*   Updated: 2021/12/02 11:32:47 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "stack.h"

# define MIN_INT -2147483648
# define MAX_INT 2147483647

// test
typedef struct s_block
{
	int				size;
	struct s_block	*next;
}				t_block;

typedef struct s_data
{
	t_stack	*stack_a;
	t_block	*block_a;
	int		sorted_a;
	t_stack	*stack_b;
	t_block	*block_b;
	int		sorted_b;
	
}				t_data;

//		auxiliar
void	check_start_arguments(const int argc, const char **argv);
void	init(int argc, char **argv, t_data *data);
void	data_destroy(t_data *data_ref);
int		find_smaller(t_stack *stack_ref);
int		find_bigger(t_stack *stack_ref);
int		get_pivot(t_stack *block_ref, int len);
int		get_direction(t_stack *stack_ref, int value);

//		operations
void	swap(t_stack *stack_ref);
void	push(t_stack *stack_src_ref, t_stack *stack_dest_ref);
void	rotate(t_stack *stack_ref);
void	reverse_rotate(t_stack *stack_ref);
void	double_swap(t_data *data);
void	double_rotate(t_data *data);
void	double_reverse_rotate(t_data *data);

//		push_swap
void	push_swap(t_data *data);

//		sort
void	sort_stack_size_two(t_stack *stack_ref);
void	sort_stack_size_three(t_stack *stack_ref);
void	sort_stack_size_four(t_data *data);
void	sort_stack_size_two_reverse(t_stack *stack_ref);
void	sort_stack_size_five(t_data *data);
void	sort_stack_size_three_reverse(t_stack *stack_ref);
void	sort_stack_size_six(t_data *data);
int		get_hold_first(int start, int end, t_data *data);
int		get_hold_second(int start, int end, t_data *data);
void	send_hold_first(int hold_first, t_data *data);
void	send_hold_second(int hold_second, t_data *data);
void	send_chunk(int start, int chunk_size, t_data *data);
void	send_back_to_a(t_data *data);
void	sort_stack_size_up_to_hundred(t_data *data);
void	sort_stack_greater_than_hundred(t_data *data);

//	test
void	complex_sort(t_data *data);
t_block	*create_block(int value);
void	add_node_to_block(t_block *block, int value);
void	destroy_block(t_block *block);
t_block	*get_last_block(t_block *block);
void	destroy_last_block(t_block *block);
void	sort_top_a_two(t_data *data);
void	sort_top_a_three(t_data *data);
void	sort_top_b_two(t_data *data);
void	sort_top_b_three(t_data *data);
void	complex_sort_b(t_data *data);

#endif
