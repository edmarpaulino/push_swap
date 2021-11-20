/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:39:17 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/20 15:17:22 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*add_node(t_stack *stack_ref, int content)
{
	t_stack			*stack;
	t_stack_node	*node;

	stack = stack_ref;
	node = (t_stack_node *)malloc(sizeof(t_stack_node *));
	if (node)
	{
		node->next = NULL;
		node->prev = stack->top;
		node->content = content;
		if (stack->size == 0)
			stack->begin = node;
		else
			stack->top->next = node;
		stack->top = node;
		stack->size++;
	}
	return (node);
}
