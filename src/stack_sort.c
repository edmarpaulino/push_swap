/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 16:50:04 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/14 17:56:44 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	three_sort(t_stack *stack_ref)
{
	t_stack	*stack;

	stack = stack_ref;
	if ((stack->begin->content > stack->begin->next->content) \
		&& (stack->begin->content > stack->top->content))
		stack_swap(stack);
	else if ((stack->begin->content < stack->begin->next->content) \
		&& (stack->begin->content < stack->top->content) \
		&& (stack->top->content > stack->begin->next->content))
	{
		stack_rotate(stack);
		stack_swap(stack);
	}
	else if ((stack->begin->content < stack->begin->next->content) \
		&& (stack->begin->content < stack->top->content))
		stack_reverse_rotate(stack);
	else if ((stack->begin->content > stack->begin->next->content) \
		&& (stack->begin->content < stack->top->content))
		stack_rotate(stack);
	else
	{
		stack_swap(stack);
		stack_rotate(stack);
	}
}

static void	simple_sort(t_stack *stack_a_ref, t_stack *stack_b_ref)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		small;

	stack_a = stack_a_ref;
	stack_b = stack_b_ref;
	while (stack_a->size > 2)
	{
		small = find_smaller(stack_a);
		if (stack_a->top->content == small)
			stack_swap(stack_a);
		else if (stack_a->top->prev->content == small)
		{
			stack_rotate(stack_a);
			stack_rotate(stack_a);
		}
		else if (stack_a->begin->next->content == small)
		{
			stack_reverse_rotate(stack_a);
			stack_reverse_rotate(stack_a);
		}
		else if (stack_a->begin->content == small)
			stack_reverse_rotate(stack_a);
		stack_push(stack_a, stack_b);
	}
	three_sort(stack_a);
	stack_push(stack_b, stack_a);
	if (stack_a->size == 5)
		stack_push(stack_b, stack_a);
}

void	stack_sort(t_stack *stack_a_ref, t_stack *stack_b_ref)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = stack_a_ref;
	stack_b = stack_b_ref;
	if (!stack_is_sorted(stack_a))
	{
		if (stack_a->size == 2)
			stack_swap(stack_a);
		else if (stack_a->size == 3)
			three_sort(stack_a);
		else if (stack_a->size <= 5)
			simple_sort(stack_a, stack_b);
	}
}
