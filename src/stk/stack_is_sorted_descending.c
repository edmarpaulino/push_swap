/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_is_sorted_descending.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:02:59 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/23 12:05:04 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	stack_is_sorted_descending(t_stack *stack_ref)
{
	t_stack			*stack;
	t_stack_node	*node;

	if (stack_ref)
	{
		stack = stack_ref;
		node = stack->begin;
		while (node->next)
		{
			if (node->content > node->next->content)
				return (0);
			node = node->next;
		}
	}
	return (1);
}
