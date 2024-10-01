/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:16:54 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/10/01 18:48:42 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	rotate_both(t_stack_node **a, t_stack_node **b, \
		t_stack_node *cheapest)
{
	while (*a != cheapest->target_node && *b != cheapest)
		rr(a, b, false);
	set_index(*a);
	set_index(*b);
}

static void	reverse_rotate_both(t_stack_node **a, t_stack_node **b, \
		t_stack_node *cheapest)
{
	while (*a != cheapest->target_node && *b != cheapest)
		rrr(a, b, false);
	set_index(*a);
	set_index(*b);
}

void	prep_push(t_stack_node **stack, t_stack_node *head_node, \
		char stack_name)
{
	while (*stack != head_node)
	{
		if (stack_name == 'a')
		{
			if (head_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (head_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

static void	move_nodes(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = return_cheapest(*b);
	if (cheapest_node->above_median && \
			cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median) && \
			!(cheapest_node->target_node->above_median))
		reverse_rotate_both(a, b, cheapest_node);
	prep_push(b, cheapest_node, 'b');
	prep_push(a, cheapest_node->target_node, 'a');
	pa(a, b, false);
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a == 5)
		sort_five(a, b);
	else
	{
		while (len_a-- > 3)
			pb(b, a, false);
	}
	sort_three(a);
	while (*b)
	{
		init_node(*a, *b);
		move_nodes(a, b);
	}
	align_on_top(a);
}
