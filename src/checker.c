/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:06:44 by edpaulin          #+#    #+#             */
/*   Updated: 2021/12/09 14:37:44 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	double_moves(t_data *data, char option)
{
	if (option == SS)
	{
		stack_swap(data->stack_a);
		stack_swap(data->stack_b);
	}
	else if (option == RR)
	{
		stack_rotate(data->stack_a);
		stack_rotate(data->stack_b);
	}
	else if (option == RRR)
	{
		stack_reverse_rotate(data->stack_a);
		stack_reverse_rotate(data->stack_b);
	}
}

static int	do_moves(t_data *data, char *cmd)
{
	if (!ft_strcmp((const char *)cmd, "sa\n"))
		stack_swap(data->stack_a);
	else if (!ft_strcmp((const char *)cmd, "sb\n"))
		stack_swap(data->stack_b);
	else if (!ft_strcmp((const char *)cmd, "ss\n"))
		double_moves(data, SS);
	else if (!ft_strcmp((const char *)cmd, "ra\n"))
		stack_rotate(data->stack_a);
	else if (!ft_strcmp((const char *)cmd, "rb\n"))
		stack_rotate(data->stack_b);
	else if (!ft_strcmp((const char *)cmd, "rr\n"))
		double_moves(data, RR);
	else if (!ft_strcmp((const char *)cmd, "rra\n"))
		stack_reverse_rotate(data->stack_a);
	else if (!ft_strcmp((const char *)cmd, "rrb\n"))
		stack_reverse_rotate(data->stack_b);
	else if (!ft_strcmp((const char *)cmd, "rrr\n"))
		double_moves(data, RRR);
	else if (!ft_strcmp((const char *)cmd, "pa\n"))
		stack_push(data->stack_b, data->stack_a);
	else if (!ft_strcmp((const char *)cmd, "pb\n"))
		stack_push(data->stack_a, data->stack_b);
	else
		return (0);
	return (1);
}

static void	get_moves(t_data *data)
{
	char	*cmd;

	cmd = get_next_line(0);
	while (cmd && *cmd != '\0')
	{
		if (!do_moves(data, cmd))
		{
			ft_putendl_fd("Error", 2);
			free(cmd);
			data_destroy(data);
			exit(EXIT_FAILURE);
		}
		free(cmd);
		cmd = get_next_line(0);
	}
	free(cmd);
	cmd = NULL;
}

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
		get_moves(data);
		if (stack_is_sorted_ascending(data->stack_a) && !data->stack_b->size)
			ft_putendl_fd("OK", 1);
		else
			ft_putendl_fd("KO", 1);
		data_destroy(data);
	}
	return (0);
}
