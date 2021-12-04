/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 21:04:32 by edpaulin          #+#    #+#             */
/*   Updated: 2021/12/04 20:24:26 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	complex_sort(t_data *data)
{
	if (stack_is_sorted_descending(data->stack_a))
		sort_descending(data);
	else
		split_stack_a(data, data->stack_a->size, NOT_HAVE_RR);
}
