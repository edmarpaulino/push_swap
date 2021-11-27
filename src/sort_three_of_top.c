/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_of_top.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 11:53:54 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/27 12:07:23 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_of_top(t_stack *stack_ref)
{
	t_stack_node	*first;
	t_stack_node	*second;
	t_stack_node	*third;
	
	if (stack_ref)
	{
		first = stack_ref->top;
		second = first->prev;
		third = second->prev;
		if (first->content > second->content \
			&& second->content > third->content)
		{
			swap(stack_ref);
			rotate(stack_ref);
			swap(stack_ref);
			reverse_rotate(stack_ref);
			swap(stack_ref);
		}
		else if (first->content > second->content \
			&& second->content < third->content)
		{
			swap(stack_ref);
			rotate(stack_ref);
			swap(stack_ref);
			reverse_rotate(stack_ref);
		}
		else if (first->content < second->content \
			&& first->content > third->content)
		{
			rotate(stack_ref);
			swap(stack_ref);
			reverse_rotate(stack_ref);
			swap(stack_ref);
		}
		else if (first->content > second->content \
			&& first->content < third->content)
			swap(stack_ref);
		else if (first->content < second->content \
			&& first->content < third->content \
			&& second->content > third->content)
		{
			rotate(stack_ref);
			swap(stack_ref);
			reverse_rotate(stack_ref);
		}
	}
}
