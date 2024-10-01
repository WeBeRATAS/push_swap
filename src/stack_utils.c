/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:25:39 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/10/01 18:57:36 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack_node	*ft_last_node(t_stack_node *upper)
{
	while (upper)
	{
		if (!upper->next)
			return (upper);
		upper = upper->next;
	}
	return (upper);
}

int	stack_len(t_stack_node *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

t_stack_node	*return_cheapest(t_stack_node *stack)
{
	t_stack_node	*cheapest_node;
	int				min_cost;

	min_cost = stack->push_cost;
	cheapest_node = stack;
	while (stack)
	{
		if (stack->push_cost < min_cost)
		{
			min_cost = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	return (cheapest_node);
}

void	align_on_top(t_stack_node **a)
{
	t_stack_node	*small_node;

	set_index(*a);
	small_node = find_small(*a);
	if (small_node->above_median)
		while (*a != small_node)
			ra(a, false);
	else
		while (*a != small_node)
			rra(a, false);
}
