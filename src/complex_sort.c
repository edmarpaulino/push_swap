/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 20:57:34 by edpaulin          #+#    #+#             */
/*   Updated: 2021/12/03 09:45:04 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/*
	ficar mandando metade de cada bloco não organizado para a outra stack
	até as duas stacks estarem organizadas
	só ordenar quando o bloco não ordenado for menor ou igual a 3
	enquanto o bloco for maior que 3 ficar mandando metade para a outra stack
*/

static int	send_half_a_to_b_first(t_data *data)
{
	int	pivot;
	int	real_size;
	int	half;
	int	push_count;

	real_size =  (data->stack_a->size - data->sorted_a);
	pivot = get_pivot(data->stack_a, real_size);
	push_count = 0;
	half = (real_size / 2);
	while ((data->stack_a->size - data->sorted_a) > half)
	{
		if (data->stack_a->top->content <= pivot)
		{
			push(data->stack_a, data->stack_b);
			push_count++;
		}
		else
			rotate(data->stack_a);
	}
	return (push_count);
}

static int	send_half_a_to_b(t_data *data)
{
	int	pivot;
	int	real_size;
	int half;
	int	push_count;
	int	rotate_count;

	real_size =  (data->stack_a->size - data->sorted_a);
	pivot = get_pivot(data->stack_a, real_size);
	push_count = 0;
	rotate_count = 0;
	half = (real_size / 2);
	while ((data->stack_a->size - data->sorted_a) > half)
	{
		if (data->stack_a->top->content <= pivot)
		{
			push(data->stack_a, data->stack_b);
			push_count++;
		}
		else
		{
			rotate(data->stack_a);
			rotate_count++;
		}
	}
	while (rotate_count-- > 0)
		reverse_rotate(data->stack_a);
	return (push_count);
}

static int	send_half_b_to_a_first(t_data *data)
{
	int	pivot;
	int	real_size;
	int	half;
	int	push_count;

	real_size = (data->stack_b->size - data->sorted_b);
	pivot = get_pivot(data->stack_b, real_size);
	push_count = 0;
	half = (real_size / 2);
	while ((data->stack_b->size - data->sorted_b) > half)
	{
		if (data->stack_b->top->content >= pivot)
		{
			push(data->stack_b, data->stack_a);
			push_count++;
		}
		else
			rotate(data->stack_b);
	}
	return (push_count);
}

static int	send_half_b_to_a(t_data *data)
{
	int	pivot;
	int	real_size;
	int	half;
	int	push_count;
	int	rotate_count;

	real_size = (data->stack_b->size - data->sorted_b);
	pivot = get_pivot(data->stack_b, real_size);
	push_count = 0;
	rotate_count = 0;
	half = (real_size / 2);
	while ((data->stack_b->size - data->sorted_b) > half)
	{
		if (data->stack_b->top->content >= pivot)
		{
			push(data->stack_b, data->stack_a);
			push_count++;
		}
		else
		{
			rotate(data->stack_b);
			rotate_count++;
		}
	}
	while (rotate_count-- > 0)
		reverse_rotate(data->stack_b);
	return (push_count);
}

static void	sort_a_first(t_data *data)
{
	int	push_count;

	while (data->stack_a->size > 3)
		push_count = send_half_a_to_b_first(data);
	if (data->stack_a->size == 2)
		sort_stack_size_two(data->stack_a);
	else if (data->stack_a->size == 3)
		sort_stack_size_three(data->stack_a);
	data->sorted_a = data->stack_a->size;
	if (push_count == 2)
		sort_top_b_two(data);
	else if (push_count == 3)
		sort_top_b_three(data);
	while (push_count-- > 0)
	{
		push(data->stack_b, data->stack_a);
		data->sorted_a++;
	}
}

static void	sort_a(t_data *data)
{
	int	push_count;

	while ((data->stack_a->size - data->sorted_a) > 3)
		push_count = send_half_a_to_b(data);
	if ((data->stack_a->size - data->sorted_a) == 2)
		sort_top_a_two(data);
	else if ((data->stack_a->size - data->sorted_a) == 3)
		sort_top_a_three(data);
	data->sorted_a = data->stack_a->size;
	if (push_count == 2)
		sort_top_b_two(data);
	else if (push_count == 3)
		sort_top_b_three(data);
	while (push_count-- > 0)
	{
		push(data->stack_b, data->stack_a);
		data->sorted_a++;
	}
}

static void	sort_b_first(t_data *data)
{
	int	push_count;

	while (data->stack_b->size > 3)
		push_count = send_half_b_to_a_first(data);
	if (data->stack_b->size == 2)
		sort_stack_size_two_reverse(data->stack_b);
	else if (data->stack_b->size == 3)
		sort_stack_size_three_reverse(data->stack_b);
	data->sorted_b = data->stack_b->size;
	if (push_count == 2)
		sort_top_a_two(data);
	else if (push_count == 3)
		sort_top_a_three(data);
	while (push_count-- > 0)
	{
		push(data->stack_a, data->stack_b);
		data->sorted_b++;
	}
}

static void	sort_b(t_data *data)
{
	int	push_count;

	while ((data->stack_b->size - data->sorted_b) > 3)
		push_count = send_half_b_to_a(data);
	if ((data->stack_b->size - data->sorted_b) == 2)
		sort_top_b_two(data);
	else if ((data->stack_b->size - data->sorted_b) == 3)
		sort_top_b_three(data);
	data->sorted_b += (data->stack_b->size - data->sorted_b);
	if (push_count == 2)
		sort_top_a_two(data);
	else if (push_count == 3)
		sort_top_a_three(data);
	while (push_count-- > 0)
	{
		push(data->stack_a, data->stack_b);
		data->sorted_b++;
	}
}

static void	complex_complex(t_data *data)
{
	sort_a(data);
	sort_b(data);
	if(data->sorted_a == data->stack_a->size \
		 && data->sorted_b == data->stack_b->size)
	{
		while (data->stack_b->size > 0)
			push(data->stack_b, data->stack_a);
	}
	else
		complex_complex(data);
}

void	complex_sort(t_data *data)
{
	sort_a_first(data);
	sort_b_first(data);
	complex_complex(data);
}
