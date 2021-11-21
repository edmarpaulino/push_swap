/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 12:30:40 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/21 12:32:37 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack_node	*node_create(int content)
{
	t_stack_node	*node;

	node = malloc(sizeof(t_stack_node));
	if (node)
	{
		node->content = content;
		node->next = NULL;
		node->prev = NULL;
	}
	return (node);
}
