/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:43:23 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/22 11:57:36 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	simple_rotate(t_stack *stack_ref)
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

static void	complex_rotate(t_stack *stack_ref)
{
	t_stack			*stack;
	t_stack_node	*new_begin;

	stack = stack_ref;
	new_begin = stack->top;
	stack->top = stack->top->prev;
	stack->top->next = NULL;
	stack->begin->prev = new_begin;
	new_begin->next = stack->begin;
	stack->begin = new_begin;
	stack->begin->prev = NULL;
}

void	stack_rotate(t_stack *stack_ref)
{
	if (stack_ref && stack_ref->size > 1)
	{
		if (stack_ref->size == 2)
			simple_rotate(stack_ref);
		else
			complex_rotate(stack_ref);
	}
}
