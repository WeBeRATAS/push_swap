/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:17:47 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/09/16 18:42:12 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack_node	*find_max(t_stack_node *a)
{
	t_stack_node	*max;

	if (!a)
		put_error();
	max = a;
	while (max)
	{
		if (a->num > max->num)
			max = a;
		a = a->next;
	}
	return (max);
}

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest_node;

	if (!a || !*a)
		put_error();
	biggest_node = find_max(*a);
	if (biggest_node == *a)
		ra(a, false);
	else if (biggest_node == (*a)->next)
		rra(a, false);
	else if ((*a)->num > (*a)->next->num)
		sa(a, false);
}
