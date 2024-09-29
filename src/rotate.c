/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 20:07:19 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/09/29 22:42:20 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ra(t_stack_node **a, bool print)
{
	t_stack_node	*tmp;
	t_stack_node	*last;

	tmp = *a;
	*a = (*a)->next;
	last = tmp;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
	if (!print)
		ft_putendl_fd("ra", 1);
}

void	rb(t_stack_node **b, bool print)
{
	t_stack_node	*tmp;
	t_stack_node	*last;

	tmp = *b;
	*b = (*b)->next;
	last = tmp;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
	if (!print)
		ft_putendl_fd("rb", 1);
}

void	rr(t_stack_node **a, t_stack_node **b, bool print)
{
	ra(a, false);
	rb(b, false);
	if (!print)
		ft_putendl_fd("rr", 1);
}
