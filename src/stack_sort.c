/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 14:39:22 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/20 15:20:15 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_direction(t_stack *stack_ref, int value)
{
	t_stack			*stack;
	t_stack_node	*node;
	int				half;
	int				counter;

	stack = stack_ref;
	half = stack->size / 2;
	node = stack->top;
	counter = 0;
	while (node->content != value)
	{
		node = node->prev;
		counter++;
	}
	if (counter > half)
		return (0);
	return (1);
}

static void	put_bigger_on_top(t_stack *stack_ref)
{
	t_stack	*stack;
	int		bigger;
	int		direction;

	stack = stack_ref;
	bigger = find_bigger(stack);
	direction = get_direction(stack, bigger);
	if (direction == 1)
	{
		while (stack->top->content != bigger)
			stack_rotate(stack);
	}
	else
	{
		while (stack->top->content != bigger)
			stack_reverse_rotate(stack);
	}
}

static void	send_back_to_a(t_stack *stack_a_ref, t_stack *stack_b_ref)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = stack_a_ref;
	stack_b = stack_b_ref;
	while (stack_b->size > 0)
	{
		put_bigger_on_top(stack_b);
		stack_push(stack_b, stack_a);
	}
}

void	stack_sort(t_stack *stack_a_ref, t_stack *stack_b_ref)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		bigger;

	stack_a = stack_a_ref;
	stack_b = stack_b_ref;
	bigger = find_bigger(stack_a);
	while (stack_a->size > 1)
	{
		if (stack_a->top->content == bigger)
			stack_rotate(stack_a);
		else
			stack_push(stack_a, stack_b);
	}
	send_back_to_a(stack_a, stack_b);
	if (!stack_is_sorted(stack_a))
		stack_sort(stack_a, stack_b);
}
