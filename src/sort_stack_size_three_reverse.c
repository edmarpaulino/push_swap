/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_size_three_reverse.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:07:17 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/26 11:17:07 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_size_three_reverse(t_stack *stack_ref)
{
	if (stack_ref)
	{
		if (stack_ref->top->content == find_smaller(stack_ref) \
			&& stack_ref->begin->content == find_bigger(stack_ref))
		{
			rotate(stack_ref);
			swap(stack_ref);
		}
		else if (stack_ref->begin->content > stack_ref->begin->next->content \
			&& stack_ref->begin->content < stack_ref->top->content)
		{
			swap(stack_ref);
			rotate(stack_ref);
		}
		else if (stack_ref->begin->content < stack_ref->begin->next->content \
			&& stack_ref->begin->content > stack_ref->top->content)
			rotate(stack_ref);
		else if (stack_ref->top->content > stack_ref->top->prev->content \
			&& stack_ref->top->content < stack_ref->begin->content)
			reverse_rotate(stack_ref);
		else if (stack_ref->top->content < stack_ref->top->prev->content \
			&& stack_ref->top->content > stack_ref->begin->content)
			swap(stack_ref);
	}
}
