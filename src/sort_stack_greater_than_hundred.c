/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_greater_than_hundred.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 10:44:12 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/30 10:45:18 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_in_range(int value, int start, int end)
{
	return (value >= start && value <= end);
}

static void	send_chunk(int start, int chunk_size, t_data *data)
{
	int				hold_first;
	int				hold_first_moves;
	int				hold_second;
	int				hold_second_moves;
	t_stack_node	*node;

	node = data->stack_a->top;
	while (node && !is_in_range(node->content, start, start + chunk_size))
		node = node->prev;
	hold_first = node->content;
	node = data->stack_a->begin;
	while (node && !is_in_range(node->content, start, start + chunk_size))
		node = node->next;
	hold_second = node->content;
	hold_first_moves = get_direction(data->stack_a, hold_first);
	hold_second_moves = get_direction(data->stack_a, hold_second);
	hold_second_moves = (data->stack_a->size - hold_second_moves) + 1;
	if (hold_first_moves < hold_second_moves)
	{
		while (data->stack_a->top->content != hold_first)
			rotate(data->stack_a);
		push(data->stack_a, data->stack_b);
	}
	else
	{
		while (data->stack_a->top->content != hold_second)
			reverse_rotate(data->stack_a);
		push(data->stack_a, data->stack_b);
	}
}

void	sort_stack_greater_than_hundred(t_data *data)
{
	int	range;
	int	chunk_size;
	int	chunk_size_last;
	int	index;

	range = find_bigger(data->stack_a) - find_smaller(data->stack_a);
	chunk_size = range / 11;
	chunk_size_last = range - (chunk_size * 10);
	index = 0;
	while (index < 10 && data->stack_a->size > 0)
	{
		while (find_smaller(data->stack_a) < chunk_size)
			send_chunk(find_smaller(data->stack_a) + (chunk_size * index), chunk_size, data);
		index++;
	}
	while (data->stack_a->size > 0)
		send_chunk(find_bigger(data->stack_a) - chunk_size_last, chunk_size_last, data);
	while (data->stack_b->size > 0)
	{
		if (data->stack_b->top->content == find_bigger(data->stack_b))
			push(data->stack_b, data->stack_a);
		else
		{
			if (get_direction(data->stack_b, find_bigger(data->stack_b)) < data->stack_b->size / 2)
				rotate(data->stack_b);
			else
				reverse_rotate(data->stack_b);
		}
	}
}
