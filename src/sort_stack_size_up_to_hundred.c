/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_size_up_to_hundred.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:18:51 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/30 16:57:52 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_size_up_to_hundred(t_data *data)
{
	int	range;
	int	chunk_size;
	int	chunk_size_last;
	int	index;
	int	last_size;

	range = find_bigger(data->stack_a) - find_smaller(data->stack_a);
	chunk_size = (range / 5);
	chunk_size_last = (range - (chunk_size * 4));
	index = 1;
	while (index < 5)
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
