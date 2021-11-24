/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_b_size_three.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:12:48 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/24 18:28:12 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	first_equal_pivot(t_data *data, int pivot)
{
	if (data->stack_b->top->prev->content > pivot)
	{
		swap(data->stack_b);
		while (data->stack_b->size)
			push(data->stack_b, data->stack_a);
	}
	else
	{
		push(data->stack_b, data->stack_a);
		while (data->stack_b->size)
		{
			swap(data->stack_b);
			push(data->stack_b, data->stack_a);
		}
	}
}

static void	second_equal_pivot(t_data *data, int pivot)
{
	if (data->stack_b->top->content > pivot)
	{
		while (data->stack_b->size)
			push(data->stack_b, data->stack_a);
	}
	else
	{
		while (data->stack_b->size)
		{
			swap(data->stack_b);
			push(data->stack_b, data->stack_a);
		}
	}
}

static void	third_equal_pivot(t_data *data, int pivot)
{
	if (data->stack_b->top->content > pivot)
	{
		push(data->stack_b, data->stack_a);
		sort_stack_size_two_reverse(data->stack_b);
		push(data->stack_b, data->stack_a);
		push(data->stack_b, data->stack_a);
	}
	else
	{
		swap(data->stack_b);
		push(data->stack_b, data->stack_a);
		sort_stack_size_two_reverse(data->stack_b);
		push(data->stack_b, data->stack_a);
		push(data->stack_b, data->stack_a);
	}
}

void	sort_stack_b_size_three(t_data *data)
{
	int				pivot;
	t_stack_node	*first;
	t_stack_node	*second;
	t_stack_node	*third;

	if (data)
	{
		pivot = get_pivot(data->stack_b, data->stack_b->size, 1);
		first = data->stack_b->top;
		second = first->prev;
		third = second->prev;
		if (first->content == pivot)
			first_equal_pivot(data, pivot);
		else if (second->content == pivot)
			second_equal_pivot(data, pivot);
		else if (third->content == pivot)
			third_equal_pivot(data, pivot);

	}
}
