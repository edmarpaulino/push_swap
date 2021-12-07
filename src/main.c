/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:34:53 by edpaulin          #+#    #+#             */
/*   Updated: 2021/12/07 15:46:00 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	***splits;
	t_data	*data;

	if (argc > 1)
	{
		has_at_least_one_digit(argc, argv);
		splits = get_splits(argc, argv);
		check_start_arguments((const char ***)splits);
		data = malloc(sizeof(t_data));
		init((const char ***)splits, data);
		clear_splits(splits);
		if (!check_dup(data->stack_a))
		{
			ft_putendl_fd("Error", 2);
			data_destroy(data);
			return (1);
		}
		if (!stack_is_sorted_ascending(data->stack_a))
			push_swap(data);
		data_destroy(data);
	}
	return (0);
}
