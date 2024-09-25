/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 20:08:08 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/09/25 16:42:01 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_stack(t_stack_node **src, t_stack_node **dst)
{
	t_stack_node	*tmp;

	if (!*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	tmp->prev = NULL;
	if (*dst == NULL)
	{
		*dst = tmp;
		tmp->next = NULL;
	}
	else
	{
		tmp->next = *dst;
		tmp->next->prev = tmp;
		*dst = tmp;
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool print)
{
	push_stack(a, b);
	if (!print)
		ft_putendl_fd("pa", 1);
}

void	pb(t_stack_node **b, t_stack_node **a, bool print)
{
	push_stack(b, a);
	if (!print)
		ft_putendl_fd("pb", 1);
}
