/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:55:42 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/11 20:07:13 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_destroy(t_stack *stack_ref)
{
	t_stack			*stack;
	t_stack_node	*elem;
	t_stack_node	*aux;

	stack = stack_ref;
	elem = stack->begin;
	while (elem)
	{
		aux = elem;
		elem = elem->next;
		free(aux);
	}
	free(stack);
	stack_ref = NULL;
}
