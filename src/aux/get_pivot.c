/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:02:41 by edpaulin          #+#    #+#             */
/*   Updated: 2021/12/09 14:40:24 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*get_array(t_stack *block_ref, int len)
{
	int				i;
	int				*array;
	t_stack_node	*block_node;

	array = malloc(len * sizeof(int));
	if (array)
	{
		block_node = block_ref->top;
		i = 0;
		while (block_node && i < len)
		{
			array[i] = block_node->content;
			block_node = block_node->prev;
			i++;
		}
	}
	return (array);
}

int	get_pivot(t_stack *block_ref, int len, int flag)
{
	int	pivot;
	int	*array;

	pivot = 0;
	array = get_array(block_ref, len);
	if (array)
	{
		ft_quicksort(array, 0, (len - 1));
		if (flag == 0)
		{
			if ((len % 2) == 0)
				pivot = array[(len / 2)];
			else
				pivot = array[(len / 2) + 1];
		}
		else
		{
			if ((len % 2) == 0)
				pivot = array[(len / 2) - 1];
			else
				pivot = array[(len / 2)];
		}
		free(array);
	}
	return (pivot);
}
