/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:16:54 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/09/17 17:36:01 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_five(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*min;
	t_stack_node	*max;

	min = find_small(*a);
	max = find_big(*a);
	if (min->index < max->index)
	{
		while ((*a)->num != min->num)
			ra(a, true);
	}
	else
	{
		while ((*a)->num != min->num)
			rra(a, true);
	}
	pb(b, a, true);
	sort_three(a);
	while (*b)
		pa(a, b, true);
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	if (stack_len(*a) <= 5)
	{
		sort_five(a, b);
		return ;
	}
	if (stack_len(*a) <= 100)
	{
		sort_five(a, b);
		return ;
	}
	if (stack_len(*a) <= 500)
	{
		sort_five(a, b);
		return ;
	}
}
