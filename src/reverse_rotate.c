/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 20:05:09 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/09/29 22:42:34 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rra(t_stack_node **a, bool print)
{
	t_stack_node	*tmp;
	t_stack_node	*last;

	last = *a;
	while (last->next->next)
		last = last->next;
	tmp = last->next;
	last->next = NULL;
	tmp->next = *a;
	*a = tmp;
	if (!print)
		ft_putendl_fd("rra", 1);
}

void	rrb(t_stack_node **b, bool print)
{
	t_stack_node	*tmp;
	t_stack_node	*last;

	last = *b;
	while (last->next->next)
		last = last->next;
	tmp = last->next;
	last->next = NULL;
	tmp->next = *b;
	*b = tmp;
	if (!print)
		ft_putendl_fd("rrb", 1);
}

void	rrr(t_stack_node **a, t_stack_node **b, bool print)
{
	rra(a, false);
	rrb(b, false);
	if (!print)
		ft_putendl_fd("rrr", 1);
}
