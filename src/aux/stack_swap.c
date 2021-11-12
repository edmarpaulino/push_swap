/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 20:16:55 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/11 20:57:12 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_swap(t_stack *stack_ref)
{
	t_stack			*stack;
	t_stack_node	*aux;
	t_stack_node	*new_top;

	stack = stack_ref;
	if (stack->size > 1)
	{
		new_top = stack->top->prev;
		aux = stack->top->prev->prev;
		aux->next = stack->top;
		aux->next->prev = aux;
		stack->top = new_top;
		new_top->prev = aux->next;
		new_top->next = NULL;
	}
	if (stack->name == 'a')
		ft_putendl_fd("sa", 1);
	else
		ft_putendl_fd("sb", 1);
}
