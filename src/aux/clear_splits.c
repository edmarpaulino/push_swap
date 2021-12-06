/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_splits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:07:09 by edpaulin          #+#    #+#             */
/*   Updated: 2021/12/06 11:08:37 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_splits(char ***splits)
{
	int	index;

	index = 0;
	while (splits[index])
	{
		ft_clear_split(splits[index]);
		index++;
	}
	free(splits);
	splits = NULL;
}
