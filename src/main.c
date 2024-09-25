/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:52:03 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/09/25 10:29:52 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || && !ft_isnum(av[1]))
		exit(EXIT_FAILURE);
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		if (!av)
		{
			put_error();
			return (1);
		}
		if (check_args(ac, av))
			return (put_error());
		if (!(stack_init(&a, av)))
		{
			put_error();
			return (stack_free(&a),0);
		}
		else
		{
			if (!is_sorted(a))
			{
				if (stack_len(a) == 2)
					sa(&a, false);
				else if (stack_len(a) == 3)
					sort_three(&a);
				else if (stack_len(a) <= 5)
					sort_five(&a, &b);
				else
					sort_stacks(&a, &b);
			}
		}
		return (stack_free(&a), 0);
	}
	return (0);
}
