/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:34:19 by edpaulin          #+#    #+#             */
/*   Updated: 2021/12/06 11:58:59 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(const char ***splits, t_data *data)
{
	int	i;
	int	j;

	if (splits && data)
	{
		data->stack_a = stack_create('a');
		data->stack_b = stack_create('b');
		i = 0;
		while (splits[i])
		{
			j = 0;
			while (splits[i][j])
			{
				add_node_begin(data->stack_a, ft_atol(splits[i][j]));
				j++;
			}
			i++;
		}
	}
}
