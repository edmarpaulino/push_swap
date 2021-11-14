/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 12:08:21 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/14 15:39:09 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_push(t_stack *stack_src_ref, t_stack *stack_dst_ref)
{
	t_stack	*stack_src;
	t_stack	*stack_dst;

	if (stack_dst_ref)
		stack_src = stack_src_ref;
	stack_src = stack_src_ref;
	stack_dst = stack_dst_ref;
	if (stack_src->size > 0)
	{
		add_node_to_stack(stack_dst, stack_src->top->content);
		del_node_of_stack(stack_src);
	}
	if (stack_src->name == 'a')
		ft_putendl_fd("pb", 1);
	else if (stack_src->name == 'b')
		ft_putendl_fd("pa", 1);
}
