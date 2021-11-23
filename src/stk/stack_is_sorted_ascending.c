/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_is_sorted_ascending.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:10:29 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/23 11:59:56 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	stack_is_sorted_ascending(t_stack *stack_ref)
{
	t_stack			*stack;
	t_stack_node	*node;

	if (stack_ref)
	{
		stack = stack_ref;
		node = stack->top;
		while (node->prev)
		{
			if (node->content > node->prev->content)
				return (0);
			node = node->prev;
		}
	}
	return (1);
}
