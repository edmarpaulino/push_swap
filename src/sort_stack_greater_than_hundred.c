/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_greater_than_hundred.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 10:44:12 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/30 16:57:34 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_greater_than_hundred(t_data *data)
{
	int	range;
	int	chunk_size;
	int	chunk_size_last;
	int	index;
	int	last_size;

	range = find_bigger(data->stack_a) - find_smaller(data->stack_a);
	chunk_size = (range / 11);
	chunk_size_last = (range - (chunk_size * 10));
	index = 1;
	while (index < 11)
	{
		last_size = data->stack_a->size;
		while ((last_size - data->stack_a->size) < chunk_size)
			send_chunk(find_smaller(data->stack_a), chunk_size, data);
		index++;
	}
	while (data->stack_a->size > 0)
		send_chunk(find_smaller(data->stack_a), chunk_size_last, data);
	send_back_to_a(data);
}
