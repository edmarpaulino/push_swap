/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_complex_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 10:01:48 by edpaulin          #+#    #+#             */
/*   Updated: 2021/12/04 17:14:31 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	sort_b(t_data *data, int block_size)
{
	if (block_size == 1)
		push(data->stack_b, data->stack_a);
	else if (block_size == 2)
		sort_two_at_top_b(data);
	else if (block_size == 3)
		sort_three_at_top_b(data);
}

static void	push_pivot(t_data *data, int *rotate_count, \
						int *block_size, int pivot)
{
	push(data->stack_b, data->stack_a);
	if (data->stack_b->top->content < pivot && *block_size != 0)
	{
		double_rotate(data);
		(*rotate_count)++;
		(*block_size)--;
	}
	else
		rotate(data->stack_a);
}

static int	partition(t_data *data, int block_size, int pivot, int *pushed)
{
	int	rotate_count;

	rotate_count = 0;
	*pushed = 0;
	while (block_size-- > 0)
	{
		if (data->stack_b->top->content > pivot)
		{
			push(data->stack_b, data->stack_a);
			(*pushed)++;
		}
		else if (data->stack_b->top->content == pivot)
			push_pivot(data, &rotate_count, &block_size, pivot);
		else
		{
			rotate(data->stack_b);
			rotate_count++;
		}
	}
	return (rotate_count);
}

void	split_stack_b(t_data *data, int block_size, int have_rrb)
{
	int	pivot;
	int	index_rrb;
	int	rotate_count;
	int	pushed;
	// printf("block_size in b: %d\n", block_size);
	if (block_size < 4)
	{
		sort_b(data, block_size);
		return ;
	}
	pivot = get_pivot(data->stack_b, block_size);
	rotate_count = partition(data, block_size, pivot, &pushed);
	split_stack_a(data, pushed, have_rrb);
	double_reverse_rotate(data);
	index_rrb = 1;
	while (have_rrb != 0 && index_rrb++ < rotate_count)
		reverse_rotate(data->stack_b);
	split_stack_b(data, rotate_count, have_rrb);
}