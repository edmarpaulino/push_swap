/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_top.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:27:35 by edpaulin          #+#    #+#             */
/*   Updated: 2021/12/04 10:27:34 by edpaulin         ###   ########.fr       */
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

void	sort_three_at_top_a(t_data *data)
{
	t_stack_node	*first;
	t_stack_node	*second;
	t_stack_node	*third;

	if (data)
	{
		first = data->stack_a->top;
		second = first->prev;
		third = second->prev;
		if (first->content < second->content \
			&& second->content > third->content \
			&&	third->content > first->content)
		{
			rotate(data->stack_a);
			swap(data->stack_a);
			reverse_rotate(data->stack_a);
		}
		else if (first->content < second->content \
			&& second->content > third->content \
			&& third->content < first->content)
		{
			rotate(data->stack_a);
			swap(data->stack_a);
			reverse_rotate(data->stack_a);
			swap(data->stack_a);
		}
		else if (first->content > second->content \
			&& second->content < third->content \
			&& third->content > first->content)
		{
			swap(data->stack_a);
		}
		else if (first->content > second->content \
			&& second->content < third->content \
			&& third->content < first->content)
		{
			swap(data->stack_a);
			rotate(data->stack_a);
			swap(data->stack_a);
			reverse_rotate(data->stack_a);
		}
		else if (first->content > second->content \
			&& second->content > third->content \
			&& third->content < first->content)
		{
			swap(data->stack_a);
			rotate(data->stack_a);
			swap(data->stack_a);
			reverse_rotate(data->stack_a);
			swap(data->stack_a);
		}
	}
}

void	sort_two_at_top_b(t_data *data)
{
	if (data)
	{
		if (data->stack_b->top->content < data->stack_b->top->prev->content)
			swap(data->stack_b);
	}
}

void	sort_three_at_top_b(t_data *data)
{
	t_stack_node	*first;
	t_stack_node	*second;
	t_stack_node	*third;

	if (data)
	{
		first = data->stack_b->top;
		second = first->prev;
		third = second->prev;
		if (first->content < second->content \
			&& second->content < third->content \
			&&	third->content > first->content)
		{
			swap(data->stack_b);
			rotate(data->stack_b);
			swap(data->stack_b);
			reverse_rotate(data->stack_b);
			swap(data->stack_b);
		}
		else if (first->content < second->content \
			&& second->content > third->content \
			&& third->content > first->content)
		{
			swap(data->stack_b);
			rotate(data->stack_b);
			swap(data->stack_b);
			reverse_rotate(data->stack_b);
		}
		else if (first->content < second->content \
			&& second->content > third->content \
			&& third->content < first->content)
		{
			swap(data->stack_b);
		}

		else if (first->content > second->content \
			&& second->content < third->content \
			&& third->content > first->content)
		{
			rotate(data->stack_b);
			swap(data->stack_b);
			reverse_rotate(data->stack_b);
			swap(data->stack_b);
		}
		else if (first->content > second->content \
			&& second->content < third->content \
			&& third->content < first->content)
		{
			rotate(data->stack_b);
			swap(data->stack_b);
			reverse_rotate(data->stack_b);
		}
	}
}
