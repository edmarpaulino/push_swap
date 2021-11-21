/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node_to_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 12:24:31 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/21 12:34:16 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	add_node_to_stack(t_stack *stack_ref, int content)
{
	t_stack			*stack;
	t_stack_node	*node;

	if (stack_ref)
	{
		node = node_create(content);
		if (node)
		{
			stack = stack_ref;
			if (stack->size == EMPTY)
			{
				stack->begin = node;
				stack->top = node;
			}
			else
			{
				node->prev = stack->top;
				stack->top->next = node;
				stack->top = node;
			}
			stack->size++;
		}
	}
}
