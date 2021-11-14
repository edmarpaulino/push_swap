/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:34:53 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/14 17:54:03 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	check_start_arguments(argc, (const char **)argv);
	stack_a = stack_create('a');
	stack_b = stack_create('b');
	init(stack_a, argc, argv);
	stack_sort(stack_a, stack_b);
	stack_destroy(stack_a);
	stack_destroy(stack_b);
	return (0);
}
