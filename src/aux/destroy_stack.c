/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:55:42 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/20 15:17:12 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	destroy_stack(t_stack *stack_ref)
{
	t_stack			*stack;
	t_stack_node	*aux;
	t_stack_node	*node;

	stack = stack_ref;
	node = stack->top;
	while (node)
	{
		aux = node;
		node = node->prev;
		free(aux);
	}
	free(stack);
	stack_ref = NULL;
}
