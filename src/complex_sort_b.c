/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:13:11 by edpaulin          #+#    #+#             */
/*   Updated: 2021/12/02 20:32:23 by edpaulin         ###   ########.fr       */
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

void	send_half_block_to_a(t_data *data)
{
	int	pivot;
	int	start_size_a;
	int	half;
	int	count;

	start_size_a = data->stack_a->size;
	pivot = get_pivot(data->stack_b, data->block_b->size);
	half = get_half(data->block_b->size);
	count = 0;
	while (data->block_b->size > half)
	{
		if (data->stack_b->top->content > pivot)
		{
			push(data->stack_b, data->stack_a);
			data->block_b->size--;
		}
		else
		{
			rotate(data->stack_b);
			count++;
		}
	}
	while (count-- > 0)
	{
		reverse_rotate(data->stack_b);
	}
	add_node_to_block(data->block_a, (data->stack_a->size - start_size_a));
}

void	complex_sort_b(t_data *data)
{
	t_block	*last_block;

	last_block = get_last_block(data->block_b);
	if (last_block->size == 2)
	{
		sort_top_b_two(data);
		while (last_block->size-- > 0)
		{
			push(data->stack_b, data->stack_a);
			data->sorted_a++;
		}
	}
	else if (last_block->size == 3)
	{
		sort_top_b_three(data);
		while (last_block->size-- > 0)
		{
			push(data->stack_b, data->stack_a);
			data->sorted_a++;
		}
	}
	send_half_block_to_a(data);
}
