/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:34:53 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/10 10:27:28 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int	index;

	if (argc == 1)
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	check_start_arguments(argc, (const char **)argv);
	index = 1;
	while (index < argc)
		ft_putendl_fd(argv[index++], 1);
	ft_putendl_fd("OK", 1);
	return (0);
}
