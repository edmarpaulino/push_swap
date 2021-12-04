/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_descending.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:24:41 by edpaulin          #+#    #+#             */
/*   Updated: 2021/12/04 20:43:17 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_descending(t_data *data)
{
	rotate(data->stack_a);
	rotate(data->stack_a);
	rotate(data->stack_a);
	while (data->stack_a->size > 3)
		push(data->stack_a, data->stack_b);
	// sort_stack_size_three(data->stack_a);
	double_swap(data);
	double_reverse_rotate(data);
	while (data->stack_b->size > 0)
	{
		push(data->stack_b, data->stack_a);
		if (data->stack_b->size > 2)
			reverse_rotate(data->stack_b);
	}
}
