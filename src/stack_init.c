/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:36:17 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/10/01 12:55:18 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	put_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

bool	is_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	stack_free(t_stack_node **stack)
{
	t_stack_node	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		(*stack)->num = 0;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	add_node(t_stack_node **stack, int num, int index)
{
	t_stack_node	*new;
	t_stack_node	*last;

	if (stack == NULL)
		return ;
	new = malloc(sizeof(t_stack_node));
	if (!new)
		exit(EXIT_FAILURE);
	new->next = NULL;
	new->num = num;
	new->index = index;
	if (!(*stack))
	{
		*stack = new;
		new->prev = NULL;
	}
	else
	{
		last = ft_last_node(*stack);
		last->next = new;
		new->prev = last;
	}
}

void	stack_init(t_stack_node **a, char **av)
{
	long			n;
	int				i;
	t_stack_node	*tmp;

	i = 0;
	while (av[i])
	{
		n = ft_atol(av[i]);
		add_node(a, (int)n, i);
		i++;
	}
	tmp = *a;
	(void)tmp;
}
