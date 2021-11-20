/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_bigger.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 14:43:28 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/20 14:48:40 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_bigger(t_stack *stack_ref)
{
	t_stack			*stack;
	t_stack_node	*node;
	int				bigger;

	stack = stack_ref;
	node = stack->begin;
	bigger = node->content;
	while (node)
	{
		if (bigger < node->content)
			bigger = node->content;
		node = node->next;
	}
	return (bigger);
}
