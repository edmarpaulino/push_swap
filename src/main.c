/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:34:53 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/11 20:53:58 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int				index;
	t_stack			*stack;
	t_stack_node	*aux;

	if (argc == 1)
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	check_start_arguments(argc, (const char **)argv);
	index = argc;
	stack = stack_create('a');
	if (stack)
	{
		while (--index)
			add_node_to_stack(stack, ft_atoi(argv[index]));
		printf("stack name:	%c\n", stack->name);
		printf("stack top:	%d\n", stack->top->content);
		printf("stack begin:	%d\n", stack->begin->content);
		printf("stack size:	%d\n\n", stack->size);
		aux = stack->top;
		while (aux)
		{
			printf("%d\n", aux->content);
			aux = aux->prev;
		}
		stack_swap(stack);
		printf("stack name:	%c\n", stack->name);
		printf("stack top:	%d\n", stack->top->content);
		printf("stack begin:	%d\n", stack->begin->content);
		printf("stack size:	%d\n\n", stack->size);
		aux = stack->top;
		while (aux)
		{
			printf("%d\n", aux->content);
			aux = aux->prev;
		}
		stack_rotate(stack);
		printf("stack name:	%c\n", stack->name);
		printf("stack top:	%d\n", stack->top->content);
		printf("stack begin:	%d\n", stack->begin->content);
		printf("stack size:	%d\n\n", stack->size);
		aux = stack->top;
		while (aux)
		{
			printf("%d\n", aux->content);
			aux = aux->prev;
		}
		stack_reverse_rotate(stack);
		printf("stack name:	%c\n", stack->name);
		printf("stack top:	%d\n", stack->top->content);
		printf("stack begin:	%d\n", stack->begin->content);
		printf("stack size:	%d\n\n", stack->size);
		aux = stack->top;
		while (aux)
		{
			printf("%d\n", aux->content);
			aux = aux->prev;
		}
		stack_destroy(stack);
		ft_putendl_fd("OK", 1);
	}
	return (0);
}
