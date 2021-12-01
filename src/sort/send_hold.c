/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_hold.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:02:30 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/30 16:25:10 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	send_hold_first(int hold_first, t_data *data)
{
	while (data->stack_a->top->content != hold_first)
		rotate(data->stack_a);
	push(data->stack_a, data->stack_b);
}

void	send_hold_second(int hold_second, t_data *data)
{
	while (data->stack_a->top->content != hold_second)
		reverse_rotate(data->stack_a);
	push(data->stack_a, data->stack_b);
}
