/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_size_two_reverse.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:40:28 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/24 17:41:56 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_size_two_reverse(t_stack *stack_ref)
{
	if (stack_ref)
	{
		if (stack_ref->top->content < stack_ref->begin->content)
			swap(stack_ref);
	}
}
