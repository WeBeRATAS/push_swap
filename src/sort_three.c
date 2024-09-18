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

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest_node;

	if (!a || !*a)
		put_error();
	biggest_node = find_big(*a);
	if ((biggest_node->num == (*a)->num))
		ra(a, false);
	else if (biggest_node->num == (*a)->next->num)
		rra(a, false);
	else if ((*a)->num > (*a)->next->num)
		sa(a, false);
}
