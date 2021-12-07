/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_start_arguments.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 10:13:34 by edpaulin          #+#    #+#             */
/*   Updated: 2021/12/07 18:38:45 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_dup(t_stack *stack_ref)
{
	t_stack_node	*node;
	t_stack_node	*jumper;

	if (stack_ref)
	{
		node = stack_ref->top;
		while (node)
		{
			jumper = node->prev;
			while (jumper)
			{
				if (jumper->content == node->content)
					return (0);
				jumper = jumper->prev;
			}
			node = node->prev;
		}
	}
	return (1);
}

static int	check_type(const char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		if (ft_atol(split[i]) > MAX_INT || ft_atol(split[i]) < MIN_INT)
			return (0);
		i++;
	}
	return (1);
}

static int	check_len(const char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		if (ft_strlen(split[i]) > 11)
			return (0);
		i++;
	}
	return (1);
}

static int	check_is_digit(const char **split)
{
	int	i;
	int	j;

	i = 0;
	while (split[i])
	{
		j = 0;
		while (split[i][j])
		{
			if (!(j == 0 && split[i][j] == '-') \
				&& !ft_isdigit(split[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	check_start_arguments(const char ***splits)
{
	int	i;

	i = 0;
	while (splits[i])
	{
		if (!check_is_digit(splits[i]) \
			|| !check_len(splits[i]) \
			|| !check_type(splits[i]))
		{
			ft_putendl_fd("Error", 2);
			clear_splits((char ***)splits);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
