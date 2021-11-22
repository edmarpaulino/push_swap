/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:01:03 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/22 13:47:11 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	simple_reverse_rotate(t_stack *stack_ref)
{
	t_stack			*stack;
	t_stack_node	*aux;

	stack = stack_ref;
	aux = stack->top;
	stack->top = stack->begin;
	stack->begin = aux;
	stack->top->next = NULL;
	stack->begin->prev = NULL;
	stack->top->prev = stack->begin;
	stack->begin->next = stack->top;
}

static void	complex_reverse_rotate(t_stack *stack_ref)
{
	t_stack			*stack;
	t_stack_node	*new_top;

	stack = stack_ref;
	new_top = stack->begin;
	stack->begin = stack->begin->next;
	stack->begin->prev = NULL;
	stack->top->next = new_top;
	new_top->prev = stack->top;
	stack->top = new_top;
	stack->top->next = NULL;
}

void	stack_reverse_rotate(t_stack *stack_ref)
{
	if (stack_ref && stack_ref->size > 1)
	{
		if (stack_ref->size == 2)
			simple_reverse_rotate(stack_ref);
		else
			complex_reverse_rotate(stack_ref);
	}
}
