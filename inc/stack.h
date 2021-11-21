/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 11:29:17 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/21 15:03:57 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "libft.h"

# define EMPTY 0

typedef struct s_stack_node
{
	int					content;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}				t_stack_node;

typedef struct s_stack
{
	t_stack_node	*top;
	t_stack_node	*begin;
	int				size;
}				t_stack;

t_stack			*stack_create(void);
void			stack_destroy(t_stack *stack_ref);
t_stack_node	*node_create(int content);
void			add_node_to_stack(t_stack *stack_ref, int content);
void			stack_swap(t_stack *stack_ref);

#endif
