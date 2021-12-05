/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_top_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 21:27:57 by edpaulin          #+#    #+#             */
/*   Updated: 2021/12/05 10:42:19 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_at_top_b(t_data *data)
{
	if (data)
	{
		if (data->stack_b->top->content < data->stack_b->top->prev->content)
			swap(data->stack_b);
		push(data->stack_b, data->stack_a);
		push(data->stack_b, data->stack_a);
	}
}

static void	bigger_at_top(t_data *data, t_sort *sort)
{
	if (sort->first > sort->second \
		&& sort->second < sort->third \
		&& sort->third < sort->first)
	{
		push(data->stack_b, data->stack_a);
		sort->index--;
		swap(data->stack_b);
	}
}

static void	middle_at_top(t_data *data, t_sort *sort)
{
	if (sort->first < sort->second \
		&& sort->second > sort->third \
		&& sort->third < sort->first)
	{
		swap(data->stack_b);
	}
	else if (sort->first > sort->second \
		&& sort->second < sort->third \
		&& sort->third > sort->first)
	{
		rotate(data->stack_b);
		swap(data->stack_b);
		reverse_rotate(data->stack_b);
		swap(data->stack_b);
	}
	else
		bigger_at_top(data, sort);
}

static void	smaller_at_top(t_data *data, t_sort *sort)
{
	if (sort->first < sort->second \
		&& sort->second < sort->third \
		&& sort->third > sort->first)
	{
		swap(data->stack_b);
		rotate(data->stack_b);
		swap(data->stack_b);
		reverse_rotate(data->stack_b);
		swap(data->stack_b);
	}
	else if (sort->first < sort->second \
		&& sort->second > sort->third \
		&& sort->third > sort->first)
	{
		swap(data->stack_b);
		push(data->stack_b, data->stack_a);
		sort->index--;
		swap(data->stack_b);
	}
	else
		middle_at_top(data, sort);
}

void	sort_three_at_top_b(t_data *data)
{
	t_sort	sort;

	if (data)
	{
		sort.first = data->stack_b->top->content;
		sort.second = data->stack_b->top->prev->content;
		sort.third = data->stack_b->top->prev->prev->content;
		sort.index = 3;
		smaller_at_top(data, &sort);
		while (sort.index-- > 0)
			push(data->stack_b, data->stack_a);
	}
}
