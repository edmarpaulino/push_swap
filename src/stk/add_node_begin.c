/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node_begin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:53:34 by edpaulin          #+#    #+#             */
/*   Updated: 2021/12/06 11:56:30 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	add_node_begin(t_stack *stack_ref, int content)
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
				node->next = stack->begin;
				stack->begin->prev = node;
				stack->begin = node;
			}
			stack->size++;
		}
	}
}
