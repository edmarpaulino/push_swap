/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:37:32 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/26 11:08:09 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "stack.h"

# define MIN_INT -2147483648
# define MAX_INT 2147483647

typedef struct s_data
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}				t_data;

void	check_start_arguments(const int argc, const char **argv);
void	swap(t_stack *stack_ref);
void	push(t_stack *stack_src_ref, t_stack *stack_dest_ref);
void	rotate(t_stack *stack_ref);
void	reverse_rotate(t_stack *stack_ref);
void	double_swap(t_data *data);
void	double_rotate(t_data *data);
void	double_reverse_rotate(t_data *data);
void	init(int argc, char **argv, t_data *data);
void	data_destroy(t_data *data_ref);
void	push_swap(t_data *data);
void	sort_stack_size_two(t_stack *stack_ref);
int		find_smaller(t_stack *stack_ref);
int		find_bigger(t_stack *stack_ref);
void	sort_stack_size_three(t_stack *stack_ref);
int		get_direction(t_stack *stack_ref, int value);
void	sort_stack_size_four(t_data *data);
int		get_pivot(t_stack *block_ref, int len);
void	sort_stack_size_two_reverse(t_stack *stack_ref);
void	sort_stack_size_five(t_data *data);
void	sort_stack_size_three_reverse(t_stack *stack_ref);

#endif
