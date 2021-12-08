/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_direction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:31:04 by edpaulin          #+#    #+#             */
/*   Updated: 2021/12/08 20:06:59 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_direction(t_stack *stack_ref, int value)
{
	t_stack_node	*node;
	int				count;

	count = 0;
	if (stack_ref)
	{
		node = stack_ref->top;
		while (node)
		{
			if (node->content == value)
				return (count);
			node = node->prev;
			count++;
		}
	}
	return (count);
}
