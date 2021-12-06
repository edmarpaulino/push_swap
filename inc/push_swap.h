/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:37:32 by edpaulin          #+#    #+#             */
/*   Updated: 2021/12/06 11:14:21 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "stack.h"

# define MIN_INT -2147483648
# define MAX_INT 2147483647

# define HAVE_RR 1
# define NOT_HAVE_RR 0

typedef struct s_data
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}				t_data;

typedef struct s_sort
{
	int	first;
	int	second;
	int	third;
	int	index;
}				t_sort;

//		auxiliar
void	check_start_arguments(const int argc, const char **argv);
void	init(int argc, char **argv, t_data *data);
void	data_destroy(t_data *data_ref);
int		find_smaller(t_stack *stack_ref);
int		find_bigger(t_stack *stack_ref);
int		get_pivot(t_stack *block_ref, int len, int flag);
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
void	complex_sort(t_data *data);
void	split_stack_a(t_data *data, int block_size, int have_rra);
void	split_stack_b(t_data *data, int block_size, int have_rrb);
void	sort_two_at_top_a(t_data *data);
void	sort_three_at_top_a(t_data *data);
void	sort_two_at_top_b(t_data *data);
void	sort_three_at_top_b(t_data *data);
void	sort_descending(t_data *data);

//	test
int		has_at_least_one_digit(int argc, char **argv);
void	clear_splits(char ***splits);
char	***get_splits(int argc, char **argv);

#endif
