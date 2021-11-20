/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 20:47:38 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/20 16:11:41 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_reverse_rotate(t_stack *stack_ref)
{
	t_stack			*stack;
	t_stack_node	*new_begin;

	stack = stack_ref;
	if (stack->size > 1)
	{
		new_begin = stack->begin->next;
		stack->top->next = stack->begin;
		stack->top->next->prev = stack->top;
		stack->top = stack->begin;
		stack->top->next = NULL;
		stack->begin = new_begin;
		stack->begin->prev = NULL;
	}
	if (stack->name == 'a')
		ft_putendl_fd("rra", 1);
	else
		ft_putendl_fd("rrb", 1);
}
