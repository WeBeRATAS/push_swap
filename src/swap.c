/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 20:10:29 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/09/16 20:23:42 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sa(t_stack_node **a, bool print)
{
	t_stack_node	*tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = (*a)->next;
	(*a)->next = tmp->next;
	tmp->next = *a;
	*a = tmp;
	if (print)
		ft_putendl_fd("sa", 1);
}

void	sb(t_stack_node **b, bool print)
{
	t_stack_node	*tmp;

	if (!*b || !(*b)->next)
		return ;
	tmp = (*b)->next;
	(*b)->next = tmp->next;
	tmp->next = *b;
	*b = tmp;
	if (print)
		ft_putendl_fd("sb", 1);
}

void	ss(t_stack_node **a, t_stack_node **b, bool print)
{
	sa(a, false);
	sb(b, false);
	if (print)
		ft_putendl_fd("ss", 1);
}
