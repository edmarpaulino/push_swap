/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_splits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:09:59 by edpaulin          #+#    #+#             */
/*   Updated: 2021/12/06 11:23:13 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	***get_splits(int argc, char **argv)
{
	char	***splits;
	int		index;

	splits = malloc(argc * sizeof(char **));
	if (splits)
	{
		index = 0;
		while ((index + 1) < argc)
		{
			splits[index] = ft_split_space(argv[index + 1]);
			if (!splits[index])
			{
				clear_splits(splits);
				return (NULL);
			}
			index++;
		}
		splits[index] = NULL;
	}
	return (splits);
}
