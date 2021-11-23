/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:08:09 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/23 12:17:10 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_data *data)
{
	if (stack_is_sorted_descending(data->stack_a))
		sort_stack_reverse(data);
	else if (data->stack_a->size == 2)
		sort_stack_size_two(data->stack_a);
	else if (data->stack_a->size == 3)
		sort_stack_size_three(data);
	else if (data->stack_a->size == 4)
		sort_stack_size_four(data);
	else if (data->stack_a->size == 5 || data->stack_a->size == 6)
		simple_sort(data);
	else
		complex_sort(data);
}
