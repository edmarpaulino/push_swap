/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:53:41 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/24 18:51:11 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_a(t_stack *stack_ref, int pivot)
{
	if (stack_ref->top->content == pivot)
	{
		if (stack_ref->top->prev->content > pivot)
			reverse_rotate(stack_ref);
		else
			swap(stack_ref);
	}
	else if (stack_ref->top->prev->content == pivot)
	{
		if (stack_ref->top->content > pivot)
		{
			rotate(stack_ref);
			swap(stack_ref);
		}
	}
	else
	{
		if (stack_ref->top->content > pivot)
			rotate(stack_ref);
		else
		{
			swap(stack_ref);
			rotate(stack_ref);
		}
	}
}

static void	to_b_or_not_to_b(t_data *data, int *half, int pivot_a, int pivot_b)
{
	t_stack_node	*node;

	while (*half)
	{
		node = data->stack_a->top;
		if (node->content < pivot_a)
		{
			push(data->stack_a, data->stack_b);
			if (data->stack_b->size > 0 \
				&& data->stack_b->top->content < pivot_b)
				rotate(data->stack_b);
			(*half)--;
		}
		else
			rotate(data->stack_a);
	}
}

void	simple_sort(t_data *data)
{
	int	pivot_a;
	int	pivot_b;
	int	half;
	
	if (data)
	{
		half = data->stack_a->size / 2;
		pivot_a = get_pivot(data->stack_a, data->stack_a->size, half);
		pivot_b = get_pivot(data->stack_a, data->stack_a->size, 1);
		to_b_or_not_to_b(data, &half, pivot_a, pivot_b);
		pivot_a = get_pivot(data->stack_a, data->stack_a->size, 1);
		sort_a(data->stack_a, pivot_a);
		if (data->stack_b->size == 2)
		{
			sort_stack_size_two_reverse(data->stack_b);
			push(data->stack_b, data->stack_a);
			push(data->stack_b, data->stack_a);
		}
		else
			sort_stack_b_size_three(data);
	}
}
