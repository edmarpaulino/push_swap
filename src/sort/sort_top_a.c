/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_top_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:27:35 by edpaulin          #+#    #+#             */
/*   Updated: 2021/12/05 10:49:24 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_at_top_a(t_data *data)
{
	if (data)
	{
		if (data->stack_a->top->content > data->stack_a->top->prev->content)
			swap(data->stack_a);
	}
}

static void	smaller_at_top(t_data *data, t_sort *sort)
{
	if (sort->first < sort->second \
		&& sort->second > sort->third \
		&& sort->third > sort->first)
	{
		rotate(data->stack_a);
		swap(data->stack_a);
		reverse_rotate(data->stack_a);
	}
}

static void	middle_at_top(t_data *data, t_sort *sort)
{
	if (sort->first < sort->second \
		&& sort->second > sort->third \
		&& sort->third < sort->first)
	{
		rotate(data->stack_a);
		swap(data->stack_a);
		reverse_rotate(data->stack_a);
		swap(data->stack_a);
	}
	else if (sort->first > sort->second \
		&& sort->second < sort->third \
		&& sort->third > sort->first)
	{
		swap(data->stack_a);
	}
	else
		smaller_at_top(data, sort);
}

static void	bigger_at_top(t_data *data, t_sort *sort)
{
	if (sort->first > sort->second \
		&& sort->second < sort->third \
		&& sort->third < sort->first)
	{
		swap(data->stack_a);
		rotate(data->stack_a);
		swap(data->stack_a);
		reverse_rotate(data->stack_a);
	}
	else if (sort->first > sort->second \
		&& sort->second > sort->third \
		&& sort->third < sort->first)
	{
		swap(data->stack_a);
		rotate(data->stack_a);
		swap(data->stack_a);
		reverse_rotate(data->stack_a);
		swap(data->stack_a);
	}
	else
		middle_at_top(data, sort);
}

void	sort_three_at_top_a(t_data *data)
{
	t_sort	sort;

	sort.first = data->stack_a->top->content;
	sort.second = data->stack_a->top->prev->content;
	sort.third = data->stack_a->top->prev->prev->content;
	bigger_at_top(data, &sort);
}
