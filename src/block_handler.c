/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:37:12 by edpaulin          #+#    #+#             */
/*   Updated: 2021/12/02 10:47:57 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_block	*create_block(int value)
{
	t_block	*block;

	block = malloc(sizeof(t_block));
	if (block)
	{
		block->size = value;
		block->next = NULL;
	}
	return (block);
}

void	destroy_block(t_block *block)
{
	t_block	*aux;

	if (block)
	{
		while (block)
		{
			aux = block;
			block = block->next;
			free(aux);
		}
	}
}

void	add_node_to_block(t_block *block, int value)
{
	t_block	*new_block;
	t_block *last;

	new_block = malloc(sizeof(t_block));
	if (new_block)
	{
		last = get_last_block(block);
		new_block->size = value;
		new_block->next = NULL;
		last->next = new_block;
	}
}

void	destroy_last_block(t_block *block)
{
	t_block	*aux;

	if (block)
	{
		aux = block;
		while (aux->next->next)
			aux = aux->next;
		destroy_block(aux->next);
		aux->next = NULL;
	}
}

t_block	*get_last_block(t_block *block)
{
	t_block	*last;

	if (block)
	{
		last = block;
		while (last->next)
			last = last->next;
		return (last);
	}
	return (NULL);
}
