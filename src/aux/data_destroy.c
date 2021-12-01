/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:54:51 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/22 14:58:40 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	data_destroy(t_data *data_ref)
{
	t_data	*data;

	if (data_ref)
	{
		data = data_ref;
		stack_destroy(data->stack_a);
		data->stack_a = NULL;
		stack_destroy(data->stack_b);
		data->stack_b = NULL;
		free(data);
		data_ref = NULL;
	}
}
