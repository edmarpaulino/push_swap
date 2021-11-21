/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 14:31:08 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/21 15:04:23 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	simple_swap(t_stack *stack_ref)
{
	t_stack			*stack;
	t_stack_node	*aux;
	
	stack = stack_ref;
	aux = stack->top;
	stack->top = stack->begin;
	stack->top->next = NULL;
	stack->begin = aux;
	stack->begin->next = stack->top;
	stack->begin->prev = NULL;
}

static void	complex_swap(t_stack *stack_ref)
{
	t_stack			*stack;
	t_stack_node	*first;
	t_stack_node	*second;
	t_stack_node	*third;
	
	stack = stack_ref;
	first = stack->top;
	second = stack->top->prev;
	third = second->prev;
	third->next = first;
	first->prev = third;
	first->next = second;
	second->prev = first;
	second->next = NULL;
	stack->top = second;
}

void	stack_swap(t_stack *stack_ref)
{
	if (stack_ref && stack_ref->size > 1)
	{
		if (stack_ref->size == 2)
			simple_swap(stack_ref);
		else
			complex_swap(stack_ref);
	}
}
