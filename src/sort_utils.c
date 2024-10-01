/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:40:28 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/09/30 19:47:49 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	current_index(t_stack_node *stack)
{
	int	i;
	int	median;

	i = 0;
	while (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

static void	set_target_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a_node;
	t_stack_node	*pin_node;
	long	best_idx;

	while (b)
	{
		best_idx = LONG_MAX;
		current_a_node = a;
		while (current_a_node)
		{
			if (current_a_node->num > b->num && current_a_node->num < best_idx)
			{
				best_idx = current_a_node->num;
				pin_node = current_a_node;
			}
			current_a_node = current_a_node->next;
		}
		if (best_idx == LONG_MAX)
			b->target_node = find_small(a);
		else
			b->target_node = pin_node;
		b = b->next;
	}
}

void	set_cost(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->push_cost = b->index;
		if (!(b->above_median))
		{
			b->push_cost += b->target_node->index;
			if (b->target_node->index > len_a / 2)
				b->push_cost = len_a - (b->target_node->index);
		}
		else
		{
			b->push_cost += len_b - b->index;
				if (b->target_node->index > len_a / 2)
					b->push_cost += len_a - (b->target_node->index);
		}
		b = b->next;
	}
}

void	set_cheapest(t_stack_node *b)
{
	long		cheapest_num;
	t_stack_node	*cheapest_node;

	if (!b)
		return ;
	cheapest_num = LONG_MAX;
	while (b)
	{
		if (b->push_cost < cheapest_num)
		{
			cheapest_num = b->push_cost;
			cheapest_node = b;
		}
		b = b->next;
	}
	cheapest_node->cheapest = true;
}

void	init_nodes(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_node(a, b);
	set_cost(a, b);
	set_cheapest(b);
}