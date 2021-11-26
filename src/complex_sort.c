/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:18:30 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/26 14:39:11 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	split_the_stack(t_stack *stack_src_ref, t_stack *stack_dest_ref)
{
	int	pivot;
	int	half;

	pivot = get_pivot(stack_src_ref, stack_src_ref->size);
	half = (stack_src_ref->size / 2);
	while (stack_src_ref->size > half)
	{
		if (stack_src_ref->top->content < pivot)
			push(stack_src_ref, stack_dest_ref);
		else
			rotate(stack_src_ref);
	}
}

void	complex_sort(t_data *data)
{
	while (data->stack_a->size > 3)
		split_the_stack(data->stack_a, data->stack_b);
}
