/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:34:53 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/13 19:10:04 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int				index;
	t_stack			*stack_a;
	t_stack			*stack_b;
	t_stack_node	*aux_a;
	t_stack_node	*aux_b;

	if (argc == 1)
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	check_start_arguments(argc, (const char **)argv);
	index = argc;
	stack_a = stack_create('a');
	stack_b = stack_create('b');
	if (stack_a)
	{
		while (--index)
			add_node_to_stack(stack_a, ft_atoi(argv[index]));
		index = 3;
		while (++index < argc)
			stack_push(stack_a, stack_b);
		// printf("stack_a name:	%c\n", stack_a->name);
		// printf("stack_a top:	%d\n", stack_a->top->content);
		// printf("stack_a begin:	%d\n", stack_a->begin->content);
		// printf("stack_a size:	%d\n\n", stack_a->size);
		// aux_a = stack_a->top;
		// while (aux_a)
		// {
		// 	printf("%d\n", aux_a->content);
		// 	aux_a = aux_a->prev;
		// }
	// 	stack_swap(stack_a);
	// 	printf("stack_a name:	%c\n", stack_a->name);
	// 	printf("stack_a top:	%d\n", stack_a->top->content);
	// 	printf("stack_a begin:	%d\n", stack_a->begin->content);
	// 	printf("stack_a size:	%d\n\n", stack_a->size);
	// 	aux_a = stack_a->top;
	// 	while (aux_a)
	// 	{
	// 		printf("%d\n", aux_a->content);
	// 		aux_a = aux_a->prev;
	// 	}
	// 	stack_rotate(stack_a);
	// 	printf("stack_a name:	%c\n", stack_a->name);
	// 	printf("stack_a top:	%d\n", stack_a->top->content);
	// 	printf("stack_a begin:	%d\n", stack_a->begin->content);
	// 	printf("stack_a size:	%d\n\n", stack_a->size);
	// 	aux_a = stack_a->top;
	// 	while (aux_a)
	// 	{
	// 		printf("%d\n", aux_a->content);
	// 		aux_a = aux_a->prev;
	// 	}
	// 	stack_reverse_rotate(stack_a);
		printf("stack_a name:	%c\n", stack_a->name);
		if (stack_a->size == 0)
			printf("stack_a top:	NULL\n");
		else
			printf("stack_a top:	%d\n", stack_a->top->content);
		if (stack_a->size == 0)
			printf("stack_a top:	NULL\n");
		else
			printf("stack_a begin:	%d\n", stack_a->begin->content);
		printf("stack_a size:	%d\n\n", stack_a->size);
		aux_a = stack_a->top;
		aux_b = stack_b->top;
		index = 0;
		while (aux_a || aux_b)
		{
			// printf("aux_a:%p\naux_b:%p\n", aux_a, aux_b);
			if (!aux_a && aux_b)
			{
				printf("\t\t%d\n", aux_b->content);
				aux_b = aux_b->prev;
			}
			else if (aux_a && !aux_b)
			{
				printf("%d\t\t\n", aux_a->content);
				aux_a = aux_a->prev;
			}
			else if (aux_a && aux_b)
			{
				printf("%d\t%d\n", aux_a->content, aux_b->content);
				aux_a = aux_a->prev;
				aux_b = aux_b->prev;
			}
			if ((!aux_a && !aux_b) || index++ == 8)
				break ;
		}
		// stack_push(stack_a, stack_b);
		// aux_a = stack_a->top;
		// aux_b = stack_b->top;
		// while (aux_a || aux_b)
		// {
		// 	if (!aux_a)
		// 	{
		// 		printf("\t\t%d\n", aux_b->content);
		// 		aux_b = aux_b->prev;
		// 	}
		// 	else if (!aux_b)
		// 	{
		// 		printf("%d\t\t\n", aux_a->content);
		// 		aux_a = aux_a->prev;
		// 	}
		// 	else
		// 	{
		// 		printf("%d\t%d\n", aux_a->content, aux_b->content);
		// 		aux_a = aux_a->prev;
		// 		aux_b = aux_b->prev;
		// 	}
		// 	if (!aux_a && !aux_b)
		// 		break ;
		// }
		stack_destroy(stack_a);
		stack_destroy(stack_b);
		ft_putendl_fd("OK", 1);
	}
	return (0);
}
