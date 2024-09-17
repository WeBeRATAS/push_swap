/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:25:39 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/09/17 18:43:45 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

bool	is_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack_node	*ft_last_node(t_stack_node *upper)
{
	if (!upper)
		return (NULL);
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
	if (!stack)
		put_error();
	while (stack)
	{
		stack = stack->next;
		len += 1;
	}
	printf("La len stack es: %d\n", len);
	return (len + 1);
}

t_stack_node	*find_min(t_stack_node *stack)
{
	long			min;
	t_stack_node	*min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->num < min)
		{
			min = stack->num;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_stack_node	*find_cheapest(t_stack_node *stack)
{
	t_stack_node	*cheapest;
	t_stack_node	*current;

	cheapest = find_min(stack);
	current = stack;
	while (current)
	{
		if (current->push_cost < cheapest->push_cost)
			cheapest = current;
		current = current->next;
	}
	return (cheapest);
}
