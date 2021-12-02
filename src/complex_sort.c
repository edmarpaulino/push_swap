/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:19:04 by edpaulin          #+#    #+#             */
/*   Updated: 2021/12/02 20:36:46 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	get_half(int size)
{
	int	half;

	if ((size % 2) == 0)
		half = (size / 2);
	else
		half = ((size / 2) + 1);
	return (half);
}

void	send_half_a_to_b(t_data *data)
{
	int	pivot;
	int	start_size_a;
	int	start_size_b;
	int	half;

	pivot = get_pivot(data->stack_a, data->stack_a->size);
	start_size_a = data->stack_a->size;
	start_size_b = data->stack_b->size;
	half = get_half(start_size_a);
	while (data->stack_a->size > half)
	{
		if (data->stack_a->top->content <= pivot)
			push(data->stack_a, data->stack_b);
		else
			rotate(data->stack_a);
	}
	add_node_to_block(data->block_b, (data->stack_b->size - start_size_b));
}

static void	sort_stack_a(t_data *data)
{
	if (data->stack_a->size == 2)
	{
		sort_stack_size_two(data->stack_a);
		data->sorted_a = 2;
	}
	else if (data->stack_a->size == 3)
	{
		sort_stack_size_three(data->stack_a);
		data->sorted_a = 3;
	}
}

static void	sort_stack_b_top(t_data *data, t_block *last_block)
{
	if (last_block->size == 2)
		sort_top_b_two(data);
	else if (last_block->size == 3)
		sort_top_b_three(data);
}

void	complex_sort(t_data *data)
{
	t_block	*last_block;

	while (data->stack_a->size > 3)
		send_half_a_to_b(data);
	sort_stack_a(data);
	last_block = get_last_block(data->block_b);
	if (last_block->size == 2 || last_block->size == 3)
	{
		sort_stack_b_top(data, last_block);
		while (last_block->size-- > 0)
		{
			push(data->stack_b, data->stack_a);
			data->sorted_a++;
		}
		if (last_block->size <= 0)
			destroy_last_block(data->block_b);
	}
	complex_sort_b(data);
}
