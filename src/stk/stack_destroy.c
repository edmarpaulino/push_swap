/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 12:15:41 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/21 12:20:40 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_destroy(t_stack *stack_ref)
{
	t_stack			*stack;
	t_stack_node	*node;
	t_stack_node	*temp;
	
	if (stack_ref)
	{
		stack = stack_ref;
		node = stack->top;
		while (node)
		{
			temp = node;
			node = node->prev;
			free(temp);
		}
		free(stack);
		stack_ref = NULL;
	}
}
