/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:18:30 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/27 12:38:01 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	split_stack_b(t_data *data)
{
	int	pivot;
	int	half;
	int	count;

	pivot = get_pivot(data->stack_b, data->stack_b->size);
	half = (data->stack_b->size / 2);
	count = 0;
	while (data->stack_b->size > half)
	{
		if (data->stack_b->top->content >= pivot)
			push(data->stack_b, data->stack_a);
		else
		{
			rotate(data->stack_b);
			count++;
		}
	}
	while (count--)
		reverse_rotate(data->stack_b);
}

static void	split_stack_a(t_data *data)
{
	int	pivot;
	int	half;

	pivot = get_pivot(data->stack_a, data->stack_a->size);
	half = (data->stack_a->size / 2);
	while (data->stack_a->size > half)
	{
		if (data->stack_a->top->content <= pivot)
			push(data->stack_a, data->stack_b);
		else
			rotate(data->stack_a);
	}
}

void	complex_sort(t_data *data)
{
	int	i;

	i = data->stack_a->size / 2;
	while (data->stack_a->size > 3)
		split_stack_a(data);
	while (data->stack_b->size > i)
		split_stack_b(data);
}
