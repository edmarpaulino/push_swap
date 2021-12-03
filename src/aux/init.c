/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:34:19 by edpaulin          #+#    #+#             */
/*   Updated: 2021/12/02 21:07:40 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(int argc, char **argv, t_data *data)
{
	int	index;

	if (argv && data)
	{
		data->stack_a = stack_create('a');
		data->sorted_a = 0;
		data->stack_b = stack_create('b');
		data->sorted_b = 0;
		index = (argc - 1);
		while (index > 0)
		{
			add_node_to_stack(data->stack_a, ft_atol(argv[index]));
			index--;
		}
	}
}
