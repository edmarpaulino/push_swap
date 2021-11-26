/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:02:41 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/26 15:58:59 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap2(int *list, int j, int i)
{
	int	aux;

	aux = list[j];
	list[j] = list[i];
	list[i] = aux;
}

static int	partition(int *list, int begin, int end)
{
	int	pivot;
	int	i;
	int	j;

	pivot = list[end];
	i = begin;
	j = begin;
	while (j < end)
	{
		if (list[j] <= pivot)
		{
			swap2(list, j, i);
			i++;
		}
		j++;
	}
	swap2(list, i, end);
	return (i);
}

static void	quicksort(int *list, int begin, int end)
{
	int	pivot;

	if (begin < end)
	{
		pivot = partition(list, begin, end);
		quicksort(list, begin, (pivot - 1));
		quicksort(list, (pivot + 1), end);
	}
}

static int	*get_list(t_stack *block_ref, int len)
{
	int				*list;
	int				index;
	t_stack_node	*block_node;

	list = malloc(len * sizeof(int));
	if (!list)
		return (NULL);
	block_node = block_ref->begin;
	index = 0;
	while (index < len && block_node)
	{
		list[index] = block_node->content;
		block_node = block_node->next;
		index++;
	}
	return (list);
}

int	get_pivot(t_stack *block_ref, int len)
{
	int	pivot;
	int	*temp;

	temp = get_list(block_ref, len);
	if (!temp)
		return (0);
	quicksort(temp, 0, (len - 1));
	if ((len % 2) == 0)
		pivot = temp[(len / 2) - 1];
	else
		pivot = temp[(len / 2)];
	free(temp);
	return (pivot);
}
