/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_splits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:09:59 by edpaulin          #+#    #+#             */
/*   Updated: 2021/12/07 17:16:29 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	***get_splits(int argc, char **argv)
{
	char	***splits;
	int		i;

	splits = malloc(argc * sizeof(char **));
	if (splits)
	{
		i = 0;
		while ((i + 1) < argc)
		{
			splits[i] = ft_split_space(argv[i + 1]);
			if (!splits[i])
			{
				clear_splits(splits);
				return (NULL);
			}
			i++;
		}
		splits[i] = NULL;
	}
	return (splits);
}
