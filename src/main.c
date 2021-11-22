/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:34:53 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/22 14:46:01 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	check_start_arguments(argc, (const char **)argv);
	data = malloc(sizeof(t_data));
	if (!data)
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	init(argc, argv, data);
	return (0);
}
