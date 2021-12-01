/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_size_five.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:53:41 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/29 12:14:08 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_size_five(t_data *data)
{
	int	pivot;

	if (data)
	{
		pivot = get_pivot(data->stack_a, data->stack_a->size);
		while (data->stack_a->size > 3)
		{
			if (data->stack_a->top->content < pivot)
				push(data->stack_a, data->stack_b);
			else
				rotate(data->stack_a);
		}
		sort_stack_size_three(data->stack_a);
		sort_stack_size_two_reverse(data->stack_b);
		while (data->stack_b->size > 0)
			push(data->stack_b, data->stack_a);
	}
}
