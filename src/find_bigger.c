/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_bigger.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:39:12 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/23 14:40:41 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_bigger(t_stack *stack_ref)
{
	t_stack_node	*node;
	int				bigger;

	bigger = 0;
	if (stack_ref)
	{
		node = stack_ref->top;
		bigger = node->content;
		while (node->prev)
		{
			if (bigger < node->content)
				bigger = node->content;
			node = node->prev;
		}
	}
	return (bigger);
}
