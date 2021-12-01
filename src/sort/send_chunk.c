/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:03:53 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/30 16:06:14 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	send_chunk(int start, int chunk_size, t_data *data)
{
	int				hold_first;
	int				hold_first_moves;
	int				hold_second;
	int				hold_second_moves;

	hold_first = get_hold_first(start, start + chunk_size, data);
	hold_second = get_hold_second(start, start + chunk_size, data);
	hold_first_moves = get_direction(data->stack_a, hold_first);
	hold_second_moves = get_direction(data->stack_a, hold_second);
	hold_second_moves = ((data->stack_a->size - hold_second_moves) + 1);
	if (hold_first_moves < hold_second_moves)
		send_hold_first(hold_first, data);
	else
		send_hold_second(hold_second, data);
}
