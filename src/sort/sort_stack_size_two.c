/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_size_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:09:39 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/23 14:13:25 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_size_two(t_stack *stack_ref)
{
	if (stack_ref)
	{
		if (stack_ref->top->content > stack_ref->begin->content)
			swap(stack_ref);
	}
}
