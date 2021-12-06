/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:34:53 by edpaulin          #+#    #+#             */
/*   Updated: 2021/12/06 11:33:04 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> // remove later

int	main(int argc, char **argv)
{
	char	***group;
	int		index;
	int		index_split;

	if (argc > 1)
	{
		group = get_splits(argc, argv);
		index = 0;
		while (group[index])
		{
			index_split = 0;
			while (group[index][index_split])
			{
				printf("%d - %s\n", index_split, group[index][index_split]);
				index_split++;
			}
			index++;
		}
		clear_splits(group);
	}
	return (0);
}
