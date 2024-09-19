/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:36:17 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/09/19 09:48:28 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	put_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

bool	is_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	printf("Control 5.1 llega is_sorted de comprobar que hay stack\n");
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (false);
		stack = stack->next;
		printf("Control 5.2 dentro revision is_sorted de elementos\n");
	}
	return (true);
}

void	stack_free(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack)
		return ;
	if (stack && *stack)
	{
		current = *stack;
		while (current)
		{
			tmp = current->next;
			free(current);
			current = tmp;
		}
		*stack = NULL;
	}
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

<<<<<<< HEAD
bool	stack_init(t_stack_node **a, char **av)
=======
void	stack_init(t_stack_node **a, char **av)
>>>>>>> 531f95315dc28314bd0d3daca4fd1cecda70cde0
{
	long			n;
	int				i;
	t_stack_node	*tmp;

	i = 0;
	if (*a || a)
		return (1);
	while (av[i])
	{
		n = ft_atol(av[i]);
		add_node(a, (int)n);
		i++;
	}
	tmp = *a;
	(void)tmp;
	return (0);
}
