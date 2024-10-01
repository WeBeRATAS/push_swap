/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 20:07:19 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/10/01 13:22:09 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void rotate_cmd(t_stack_node **stack)
{
	t_stack_node    *last_node;

	if (*stack == NULL || stack == NULL)
		return ;
	last_node = ft_last_node(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;                                               
}

void	ra(t_stack_node **a, bool print)
{
	rotate_cmd(a);
	if (!print)
		ft_putendl_fd("ra", 1);
}

void	rb(t_stack_node **b, bool print)
{
	rotate_cmd(b);
	if (!print)
		ft_putendl_fd("rb", 1);
}

void	rr(t_stack_node **a, t_stack_node **b, bool print)
{
	rotate_cmd(a);
	rotate_cmd(b);
	if (!print)
		ft_putendl_fd("rr", 1);
}
