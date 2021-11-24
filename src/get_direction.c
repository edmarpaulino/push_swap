/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_direction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:31:04 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/24 15:39:55 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_direction(t_stack *stack_ref, int value)
{
	t_stack_node	*node;
	int				count;

	if (stack_ref)
	{
		node = stack_ref->top;
		count = 0;
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
