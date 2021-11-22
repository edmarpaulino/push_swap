/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:37:32 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/22 14:01:12 by edpaulin         ###   ########.fr       */
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

#endif
