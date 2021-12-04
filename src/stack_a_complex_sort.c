/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_complex_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 21:10:09 by edpaulin          #+#    #+#             */
/*   Updated: 2021/12/04 20:43:35 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	sort_a(t_data *data, int block_size)
{
	if (block_size == 2)
		sort_two_at_top_a(data);
	else if (block_size == 3)
		sort_three_at_top_a(data);
}

static int 	push_pivot(t_data *data, int *rotate_count, int pivot)
{
	push(data->stack_a, data->stack_b);
	if (data->stack_a->top->content > pivot)
	{
		double_rotate(data);
		(*rotate_count)++;
	}
	else
		rotate(data->stack_b);
	return (1);
}

static int	partition(t_data *data, int sent_block, int pivot, int have_rra)
{
	int	rotate_count;
	int	pivot_moved;
	int	less_three;

	rotate_count = 0;
	pivot_moved = 0;
	less_three = sent_block < 3;

	while (sent_block > 0)
	{
		if (data->stack_a->top->content < pivot)
		{
			push(data->stack_a, data->stack_b);
			sent_block--;
		}
		else if (!less_three && data->stack_a->top->content == pivot)
			pivot_moved = push_pivot(data, &rotate_count, pivot);
		else
		{
			rotate(data->stack_a);
			rotate_count++;
		}
	}
	while (have_rra != 0 && rotate_count-- > 0)
		reverse_rotate(data->stack_a);
	return (pivot_moved);
}

void	split_stack_a(t_data *data, int block_size, int have_rra)
{
	int	sent_block;
	int	pivot;
	int	pivot_moved;

	if (block_size < 4)
	{
		sort_a(data, block_size);
		return ;
	}
	if ((block_size % 2) == 0)
		sent_block = (block_size / 2);
	else
		sent_block = ((block_size / 2) + 1);
	pivot = get_pivot(data->stack_a, block_size, 0);
	pivot_moved = partition(data, sent_block, pivot, have_rra);
	split_stack_a(data, (block_size - sent_block - pivot_moved), have_rra);
	if (pivot_moved != 0 && data->stack_b->begin->content == pivot)
	{
		reverse_rotate(data->stack_b);
		push(data->stack_b, data->stack_a);
	}
	if (sent_block != data->stack_b->size)
		split_stack_b(data, sent_block, HAVE_RR);
	else
		split_stack_b(data, sent_block, NOT_HAVE_RR);
}