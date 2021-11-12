/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 20:37:04 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/11 20:46:26 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_rotate(t_stack *stack_ref)
{
	t_stack			*stack;
	t_stack_node	*new_begin;

	stack = stack_ref;
	if (stack->size > 1)
	{
		new_begin = stack->top;
		stack->top = stack->top->prev;
		stack->top->next = NULL;
		new_begin->next = stack->begin;
		new_begin->prev = NULL;
		stack->begin = new_begin;
		stack->begin->next->prev = new_begin;
	}
	if (stack->name == 'a')
		ft_putendl_fd("ra", 1);
	else
		ft_putendl_fd("rb", 1);
}
