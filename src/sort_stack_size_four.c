/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_size_four.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:25:52 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/24 15:51:34 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_size_four(t_data *data)
{
	int	smaller;

	if (data)
	{
		smaller = find_smaller(data->stack_a);
		if (get_direction(data->stack_a, smaller) < data->stack_a->size / 2)
		{
			if (data->stack_a->top->content != smaller)
				swap(data->stack_a);
		}
		else
		{
			if (data->stack_a->begin->content != smaller)
				reverse_rotate(data->stack_a);
			reverse_rotate(data->stack_a);
		}
		push(data->stack_a, data->stack_b);
		sort_stack_size_three(data->stack_a);
		push(data->stack_b, data->stack_a);
	}
}
