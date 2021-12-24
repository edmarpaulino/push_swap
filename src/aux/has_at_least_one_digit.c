/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_at_least_one_digit.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:05:46 by edpaulin          #+#    #+#             */
/*   Updated: 2021/12/07 15:45:41 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	has_at_least_one_digit(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]))
				break ;
			j++;
		}
		if (argv[i][j] == '\0')
		{
			ft_putendl_fd("Error", 2);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
