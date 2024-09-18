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
		len++;
		stack = stack->next;
	}
	printf("La len stack es: %d\n", len);
	return (len);
}

t_stack_node	*find_big(t_stack_node *stack)
{
	t_stack_node	*max_node;
	long			max;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if ((stack->num) > (max))
		{
			max = stack->num;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

t_stack_node	*find_small(t_stack_node *stack)
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
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
