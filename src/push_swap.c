/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:08:09 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/30 16:25:22 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

	// if (stack_is_sorted_descending(data->stack_a))
	// 	sort_stack_reverse(data);
	//	stack size up to 100
	//	stack size up to 500
void	push_swap(t_data *data)
{
	if (data->stack_a->size == 2)
		sort_stack_size_two(data->stack_a);
	else if (data->stack_a->size == 3)
		sort_stack_size_three(data->stack_a);
	else if (data->stack_a->size == 4)
		sort_stack_size_four(data);
	else if (data->stack_a->size == 5)
		sort_stack_size_five(data);
	else if (data->stack_a->size == 6)
		sort_stack_size_six(data);
	else if (data->stack_a->size <= 100)
		sort_stack_size_up_to_hundred(data);
	else
		sort_stack_greater_than_hundred(data);
}
