/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:16:54 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/09/27 13:16:47 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_stacks(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*min;
	t_stack_node	*max;

	min = find_small(*a);
	max = find_big(*a);
	if (min->index < max->index)
	{
		while ((*a)->num != min->num)
			ra(a, false);
	}
	else
	{
		while ((*a)->num != min->num)
			rra(a, false);
	}
	pb(b, a, false);
	sort_three(a);
	while (*b)
		pa(a, b, false);
}
