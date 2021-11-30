/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_back_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:05:32 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/30 16:06:11 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	send_back_to_a(t_data *data)
{
	int	bigger;
	int	direction;
	int	half;

	while (data->stack_b->size > 0)
	{
		bigger = find_bigger(data->stack_b);
		if (data->stack_b->top->content == bigger)
			push(data->stack_b, data->stack_a);
		else
		{
			direction = get_direction(data->stack_b, bigger);
			half = (data->stack_b->size / 2);
			if (direction < half)
				rotate(data->stack_b);
			else
				reverse_rotate(data->stack_b);
		}
	}
}
