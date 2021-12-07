/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_splits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:07:09 by edpaulin          #+#    #+#             */
/*   Updated: 2021/12/07 15:31:57 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_splits(char ***splits)
{
	int	i;

	i = 0;
	while (splits[i])
	{
		ft_clear_split(splits[i]);
		i++;
	}
	free(splits);
	splits = NULL;
}
