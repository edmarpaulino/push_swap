/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_smaller.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 16:17:16 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/20 22:13:26 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smaller(t_stack *stack_ref)
{
	t_stack			*stack;
	t_stack_node	*node;
	int				smaller;

	stack = stack_ref;
	node = stack->begin;
	smaller = node->content;
	while (node)
	{
		if (node->content < smaller)
			smaller = node->content;
		node = node->next;
	}
	return (smaller);
}
