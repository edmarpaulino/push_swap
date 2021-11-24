/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:02:41 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/24 16:41:18 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	simple_swap(int *temp, int pos_a, int pos_b)
{
	int	aux;

	aux = temp[pos_a];
	temp[pos_a] = temp[pos_b];
	temp[pos_b] = aux;
}

static int	get_median_value(int *temp, int len, int stop)
{
	int	index;
	int	med;

	index = 0;
	med = 0;
	while (index < (len - 1))
	{
		if (temp[index] > temp[index - 1])
		{
			index++;
			continue ;
		}
		simple_swap(temp, index, med);
		index++;
		med++;
	}
	simple_swap(temp, len - 1, med);
	if (stop == med)
		return (temp[med]);
	else if (med > stop)
		return (get_median_value(temp, med, stop));
	else
		return (get_median_value(temp + med, len - med, stop - med));
}

int	get_pivot(t_stack *block_ref, int len, int stop)
{
	int				pivot;
	int				index;
	int				*temp;
	t_stack_node	*block;

	temp = malloc(len * sizeof(int));
	if (!temp)
		return (0);
	block = block_ref->top;
	index = 0;
	while (index < len && block)
	{
		temp[index] = block->content;
		block = block->prev;
		index++;
	}
	pivot = get_median_value(temp, len, stop);
	free(temp);
	return (pivot);
}
