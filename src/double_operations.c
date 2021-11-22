/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:03:32 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/22 14:08:01 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_swap(t_data *data)
{
	if (data)
	{
		stack_swap(data->stack_a);
		stack_swap(data->stack_b);
		ft_putendl_fd("ss", 1);
	}
}

void	double_rotate(t_data *data)
{
	if (data)
	{
		stack_rotate(data->stack_a);
		stack_rotate(data->stack_b);
		ft_putendl_fd("rr", 1);
	}
}

void	double_reverse_rotate(t_data *data)
{
	if (data)
	{
		stack_reverse_rotate(data->stack_a);
		stack_reverse_rotate(data->stack_b);
		ft_putendl_fd("rrr", 1);
	}
}
