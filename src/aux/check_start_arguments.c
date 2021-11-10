/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_start_arguments.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 10:13:34 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/10 10:41:14 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_dup(const int argc, const char **argv)
{
	int	arg_index;
	int	jumper;

	arg_index = 1;
	while (arg_index < argc)
	{
		jumper = arg_index + 1;
		while (jumper < argc)
		{
			if (!ft_strcmp(argv[arg_index], argv[jumper]))
				return (0);
			jumper++;
		}
		arg_index++;
	}
	return (1);
}

static int	check_type(const int argc, const char **argv)
{
	int	arg_index;

	arg_index = 1;
	while (arg_index < argc)
	{
		if (ft_atol(argv[arg_index]) > MAX_INT \
			|| ft_atol(argv[arg_index]) < MIN_INT)
			return (0);
		arg_index++;
	}
	return (1);
}

static int	check_size(const int argc, const char **argv)
{
	int	arg_index;

	arg_index = 1;
	while (arg_index < argc)
	{
		if (ft_strlen(argv[arg_index]) > 11)
			return (0);
		arg_index++;
	}
	return (1);
}

static int	check_is_digit(const int argc, const char **argv)
{
	int	arg_index;
	int	str_index;

	arg_index = 1;
	while (arg_index < argc)
	{
		str_index = 0;
		while (argv[arg_index][str_index])
		{
			if (!(str_index == 0 && argv[arg_index][str_index] == '-') \
				&& !ft_isdigit(argv[arg_index][str_index]))
				return (0);
			str_index++;
		}
		arg_index++;
	}
	return (1);
}

void	check_start_arguments(const int argc, const char **argv)
{
	if (!check_is_digit(argc, argv) || !check_size(argc, argv) \
		|| !check_type(argc, argv) || !check_dup(argc, argv))
	{
		ft_putendl_fd("Error", 2);
		exit(EXIT_FAILURE);
	}
}
