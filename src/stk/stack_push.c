/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:21:09 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/22 11:38:56 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	size_one_to_empty(t_stack *stack_src_ref, t_stack *stack_dest_ref)
{
	t_stack	*stack_src;
	t_stack	*stack_dest;

	stack_src = stack_src_ref;
	stack_dest = stack_dest_ref;
	stack_dest->top = stack_src->top;
	stack_src->top = NULL;
	stack_dest->begin = stack_src->begin;
	stack_src->begin = NULL;
	stack_dest->size++;
	stack_src->size--;
}

static void	size_one_to_size_n(t_stack *stack_src_ref, t_stack *stack_dest_ref)
{
	t_stack	*stack_src;
	t_stack	*stack_dest;

	stack_src = stack_src_ref;
	stack_dest = stack_dest_ref;
	stack_dest->top->next = stack_src->top;
	stack_src->top->prev = stack_dest->top;
	stack_dest->top = stack_src->top;
	stack_src->top = NULL;
	stack_src->begin = NULL;
	stack_dest->size++;
	stack_src->size--;
}

static void	size_n_to_empty(t_stack *stack_src_ref, t_stack *stack_dest_ref)
{
	t_stack	*stack_src;
	t_stack	*stack_dest;

	stack_src = stack_src_ref;
	stack_dest = stack_dest_ref;
	stack_dest->top = stack_src->top;
	stack_dest->begin = stack_src->top;
	stack_src->top = stack_src->top->prev;
	stack_src->top->next = NULL;
	stack_dest->begin->prev = NULL;
	stack_dest->size++;
	stack_src->size--;
}

static void	size_n_to_size_n(t_stack *stack_src_ref, t_stack *stack_dest_ref)
{
	t_stack			*stack_src;
	t_stack			*stack_dest;
	t_stack_node	*new_src_top;

	stack_src = stack_src_ref;
	stack_dest = stack_dest_ref;
	new_src_top = stack_src->top->prev;
	stack_dest->top->next = stack_src->top;
	stack_src->top->prev = stack_dest->top;
	stack_dest->top = stack_src->top;
	stack_src->top = new_src_top;
	stack_src->top->next = NULL;
	stack_dest->size++;
	stack_src->size--;
}

void	stack_push(t_stack *stack_src_ref, t_stack *stack_dest_ref)
{
	if (stack_src_ref && stack_dest_ref)
	{
		if (stack_src_ref->size == 1)
		{
			if (stack_dest_ref->size == EMPTY)
				size_one_to_empty(stack_src_ref, stack_dest_ref);
			else
				size_one_to_size_n(stack_src_ref, stack_dest_ref);
		}
		else if (stack_src_ref->size > 1)
		{
			if (stack_dest_ref->size == EMPTY)
				size_n_to_empty(stack_src_ref, stack_dest_ref);
			else
				size_n_to_size_n(stack_src_ref, stack_dest_ref);
		}
	}
}
