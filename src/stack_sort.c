/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 14:39:22 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/20 17:25:00 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_distance_from_top(t_stack *stack_ref, int value)
{
	t_stack			*stack;
	t_stack_node	*node;
	int				counter;

	stack = stack_ref;
	node = stack->top;
	counter = 0;
	while (node->content != value)
	{
		node = node->prev;
		counter++;
	}
	return (counter);
}

//	TODO:	improve this with check from top to begin and from begin to top
static int	get_direction(t_stack *stack_ref, int bigger, int smaller)
{
	t_stack			*stack;
	int				half;
	int				counter_bigger;
	int				counter_smaller;

	stack = stack_ref;
	half = stack->size / 2;
	counter_bigger = get_distance_from_top(stack, bigger);
	counter_smaller = get_distance_from_top(stack, smaller);
	if (counter_bigger > counter_smaller)
	{
		if (counter_bigger > half)
			return (2);
		return (1);
	}
	else
	{
		if (counter_smaller > half)
			return (-2);
		return (-1);
	}
}

//	TODO:	improve this with check from top to begin and from begin to top
static void	put_best_on_top(t_stack *stack_ref)
{
	t_stack	*stack;
	int		bigger;
	int		smaller;
	int		direction;

	stack = stack_ref;
	bigger = find_bigger(stack);
	smaller = find_smaller(stack);
	direction = get_direction(stack, bigger, smaller);
	if (direction < 0)
	{
		if (direction == -1)
		{
			while (stack->top->content != smaller)
				stack_rotate(stack);
		}
		else
		{
			while (stack->top->content != smaller)
				stack_reverse_rotate(stack);
		}
	}
	else
	{
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

}

//	TODO:	improve this to choose the option with the less number of movements
//			check from top to begin and from begin to top
static void	send_back_to_a(t_stack *stack_a_ref, t_stack *stack_b_ref)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		holder;

	stack_a = stack_a_ref;
	stack_b = stack_b_ref;
	holder = stack_a->top->content;
	while (stack_b->size > 0)
	{
		put_best_on_top(stack_b);
		stack_push(stack_b, stack_a);
		while (stack_a->top->content > stack_a->top->prev->content)
		{
			stack_swap(stack_a);
			stack_rotate(stack_a);
		}
		while (stack_a->top->content != holder)
			stack_reverse_rotate(stack_a);
	}
}

void	stack_sort(t_stack *stack_a_ref, t_stack *stack_b_ref)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		bigger;
	int		smaller;

	stack_a = stack_a_ref;
	stack_b = stack_b_ref;
	bigger = find_bigger(stack_a);
	smaller = find_smaller(stack_a);
	while (stack_a->size > 2)
	{
		if (stack_a->top->content == bigger || stack_a->top->content == smaller)
			stack_rotate(stack_a);
		else
			stack_push(stack_a, stack_b);
	}
	if (stack_a->top->content != smaller)
		stack_rotate(stack_a);
	send_back_to_a(stack_a, stack_b);
	if (!stack_is_sorted(stack_a))
		stack_sort(stack_a, stack_b);
}
