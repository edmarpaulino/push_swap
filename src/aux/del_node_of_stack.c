/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_node_of_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:56:23 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/13 19:00:03 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del_node_of_stack(t_stack *stack_ref)
{
	t_stack			*stack;
	t_stack_node	*node;

	stack = stack_ref;
	if (stack->size == 1)
	{
		node = stack->top;
		free(node);
		stack->top = NULL;
		stack->begin = NULL;
		stack->size--;
	}
	else if (stack->size > 1)
	{
		node = stack->top;
		stack->top = stack->top->prev;
		stack->top->next = NULL;
		free(node);
		stack->size--;
	}
}