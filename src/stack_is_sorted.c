/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_is_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 16:41:49 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/20 16:16:06 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	stack_is_sorted(t_stack *stack_ref)
{
	t_stack			*stack;
	t_stack_node	*node;

	stack = stack_ref;
	if (stack)
	{
		if (stack->size > 1)
		{
			node = stack->top;
			while (node->prev)
			{
				if (node->content < node->prev->content)
					node = node->prev;
				else
					return (0);
			}
		}
	}
	return (1);
}
