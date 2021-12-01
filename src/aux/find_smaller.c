/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_smaller.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:31:43 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/23 15:54:27 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smaller(t_stack *stack_ref)
{
	t_stack_node	*node;
	int				smaller;

	smaller = 0;
	if (stack_ref)
	{
		node = stack_ref->top;
		smaller = node->content;
		while (node)
		{
			if (smaller > node->content)
				smaller = node->content;
			node = node->prev;
		}
	}
	return (smaller);
}
