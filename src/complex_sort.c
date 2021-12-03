/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 20:57:34 by edpaulin          #+#    #+#             */
/*   Updated: 2021/12/03 08:14:09 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	ficar mandando metade de cada bloco não organizado para a outra stack
	até as duas stacks estarem organizadas
	só ordenar quando o bloco não ordenado for menor ou igual a 3
	enquanto o bloco for maior que 3 ficar mandando metade para a outra stack
*/

static void	send_half_a_to_b(t_data *data)
{
	int	pivot;
	int	real_size;
	int	half;

	real_size =  (data->stack_a->size - data->sorted_a);
	pivot = get_pivot(data->stack_a, real_size);
	if ((real_size % 2) == 0)
		half = (real_size / 2);
	else
		half = ((real_size / 2) + 1);
	while ((data->stack_a->size - data->sorted_a) > half)
	{
		if (data->stack_a->top->content <= pivot)
			push(data->stack_a, data->stack_b);
		else
			rotate(data->stack_a);
	}
}


// static void	send_half_b_to_a()
// {
	
// }

// static void	sort_a()
// {

// }

// static void	sort_b()
// {
	
// }

void	complex_sort(t_data *data)
{
	while (data->stack_a->size > 3)
		send_half_a_to_b(data);
}
