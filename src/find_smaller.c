/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_smaller.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:41:18 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/14 17:51:38 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smaller(t_stack *stack_ref)
{
	t_stack			*stack;
	t_stack_node	*aux;
	int				smaller;

	stack = stack_ref;
	smaller = stack->begin->content;
	aux = stack->begin;
	while (aux)
	{
		if (aux->content < smaller)
			smaller = aux->content;
		aux = aux->next;
	}
	return (smaller);
}
