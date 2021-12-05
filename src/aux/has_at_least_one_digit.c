/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_at_least_one_digit.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:05:46 by edpaulin          #+#    #+#             */
/*   Updated: 2021/12/05 17:16:20 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_at_least_one_digit(int argc, char **argv)
{
	int	index_argv;
	int	index_str;

	index_argv = 1;
	while (index_argv < argc)
	{
		index_str = 0;
		while (argv[index_argv][index_str])
		{
			if (ft_isdigit(argv[index_argv][index_str]))
				break ;
			index_str++;
		}
		if (argv[index_argv][index_str] == '\0')
			return (0);
		index_argv++;
	}
	return (1);
}
