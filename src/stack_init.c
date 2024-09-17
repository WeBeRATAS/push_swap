/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:36:17 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/09/17 19:01:55 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	stack_free(t_stack_node **stack)
{
	t_stack_node	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
	*stack = NULL;
}

void	add_node(t_stack_node **stack, int n)
{
	t_stack_node	*new;
	t_stack_node	*last;

	if (stack == NULL)
		return ;
	new = malloc(sizeof(t_stack_node));
	if (!new)
		exit(EXIT_FAILURE);
	new->num = n;
	new->next = NULL;
	if (!(*stack))
	{
		new->prev = NULL;
		*stack = new;
	}
	else
	{
		last = ft_last_node(*stack);
		while (last->next)
			last = last->next;
		last->next = new;
		new->prev = last;
	}
}

void	stack_init_a(t_stack_node **a, char **av)
{
	long			n;
	int				i;
	t_stack_node	*tmp;

	i = 0;
	while (av[i])
	{
		n = ft_atol(av[i]);
		add_node(a, (int)n);
		i++;
	}
	tmp = *a;
	(void)tmp;
}
