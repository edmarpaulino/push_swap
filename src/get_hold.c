/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hold.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:59:54 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/30 16:01:32 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_in_range(int value, int start, int end)
{
	return (value >= start && value <= end);
}

int	get_hold_first(int start, int end, t_data *data)
{
	t_stack_node	*node;

	node = data->stack_a->top;
	while (node && !is_in_range(node->content, start, end))
		node = node->prev;
	return (node->content);
}

int	get_hold_second(int start, int end, t_data *data)
{
	t_stack_node	*node;

	node = data->stack_a->begin;
	while (node && !is_in_range(node->content, start, end))
		node = node->next;
	return (node->content);
}
