/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 16:13:23 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/14 16:48:07 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(t_stack *stack_ref, int argc, char **argv)
{
	int		index;
	t_stack	*stack;

	stack = stack_ref;
	if (stack)
	{
		index = argc;
		while (--index > 0)
			add_node_to_stack(stack, ft_atoi(argv[index]));
	}
}
