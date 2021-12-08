/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:30:10 by edpaulin          #+#    #+#             */
/*   Updated: 2021/12/08 18:20:52 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include "stack.h"

# define SS 1
# define RR 2
# define RRR 3

typedef struct s_data
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}				t_data;

void	has_at_least_one_digit(int argc, char **argv);
void	clear_splits(char ***splits);
char	***get_splits(int argc, char **argv);
void	init(const char ***splits, t_data *data);
void	check_start_arguments(const char ***splits);
int		check_dup(t_stack *stack_ref);
void	data_destroy(t_data *data_ref);

#endif
