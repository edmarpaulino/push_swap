/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unique_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:51:02 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/22 14:01:32 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack_ref)
{
	if (stack_ref)
	{
		stack_swap(stack_ref);
		if (stack_ref->name == 'a')
			ft_putendl_fd("sa", 1);
		else if (stack_ref->name == 'b')
			ft_putendl_fd("sb", 1);
	}
}

void	push(t_stack *stack_src_ref, t_stack *stack_dest_ref)
{
	if (stack_src_ref && stack_dest_ref)
	{
		stack_push(stack_src_ref, stack_dest_ref);
		if (stack_src_ref->name == 'a')
			ft_putendl_fd("pb", 1);
		else if (stack_src_ref->name == 'b')
			ft_putendl_fd("pa", 1);
	}
}

void	rotate(t_stack *stack_ref)
{
	if (stack_ref)
	{
		stack_rotate(stack_ref);
		if (stack_ref->name == 'a')
			ft_putendl_fd("ra", 1);
		else if (stack_ref->name == 'b')
			ft_putendl_fd("rb", 1);
	}
}

void	reverse_rotate(t_stack *stack_ref)
{
	if (stack_ref)
	{
		stack_reverse_rotate(stack_ref);
		if (stack_ref->name == 'a')
			ft_putendl_fd("rra", 1);
		else if (stack_ref->name == 'b')
			ft_putendl_fd("rrb", 1);
	}
}
