/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:08:09 by edpaulin          #+#    #+#             */
/*   Updated: 2021/12/08 18:22:27 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_parser(t_data *data)
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
	else if (stack_is_sorted_descending(data->stack_a))
		sort_descending(data);
	else
		split_stack_a(data, data->stack_a->size, NOT_HAVE_RR);
}
