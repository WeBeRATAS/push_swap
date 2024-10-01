/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 20:05:09 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/10/01 13:17:02 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void reverse_rotate_stack(t_stack_node **stack)                            
{
	 t_stack_node    *last;
	 if (*stack == NULL || stack == NULL)
		 return ;
	 last = ft_last_node(*stack);
	 last->prev->next = NULL;
	 last->next = *stack;
	 last->prev = NULL;
	 *stack = last;
	 last->next->prev = last;
}                       

void	rra(t_stack_node **a, bool print)
{
	reverse_rotate_stack(a);
	if (!print)
		ft_putendl_fd("rra", 1);
}

void	rrb(t_stack_node **b, bool print)
{
	reverse_rotate_stack(b);
	if (!print)
		ft_putendl_fd("rrb", 1);
}

void	rrr(t_stack_node **a, t_stack_node **b, bool print)
{
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
	if (!print)
		ft_putendl_fd("rrr", 1);
}
