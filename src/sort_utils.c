/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:40:28 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/10/01 18:47:13 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	set_index(t_stack_node *stack)
{
	int	i;
	int	equador;

	i = 0;
	while (!stack)
		return ;
	equador = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= equador)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

static void	set_target_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			best_match_idx;

	while (b)
	{
		best_match_idx = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->num > b->num && current_a->num < best_match_idx)
			{
				best_match_idx = current_a->num;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_idx == LONG_MAX)
			b->target_node = find_small(a);
		else
			b->target_node = target_node;
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
			b->push_cost = len_b - (b->index);
		if (b->target_node->above_median)
			b->push_cost += b->target_node->index;
		else
			b->push_cost += len_a - (b->target_node->index);
		b = b->next;
	}
}

void	set_cheapest(t_stack_node *b)
{
	long			cheapest_nbr;
	t_stack_node	*cheapest_node;

	if (!b)
		return ;
	cheapest_nbr = LONG_MAX;
	while (b)
	{
		if (b->push_cost < cheapest_nbr)
		{
			cheapest_nbr = b->push_cost;
			cheapest_node = b;
		}
		b = b->next;
	}
	cheapest_node->cheapest = true;
}

void	init_node(t_stack_node *a, t_stack_node *b)
{
	set_index(a);
	set_index(b);
	set_target_node(a, b);
	set_cost(a, b);
	set_cheapest(b);
}
