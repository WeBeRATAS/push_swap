/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:52:03 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/09/25 17:00:57 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !ft_isnum(av[1])))
		exit(EXIT_FAILURE);
	if (ac >= 2)
	{
		if (!av)
		{
			put_error();
			return (1);
		}
		int i;
		i = 0;

		while (av[i])
		{
			printf("Stack a elemento %d es: %s\n", i, av[i]);
			i++;
		}
		check_args(ac, av);
		stack_init(&a, av + 1);
		if (!is_sorted(a))
		{
			if (stack_len(a) == 2)
				sa(&a, false);
			else if (stack_len(a) == 3)
				sort_three(&a);
			else
			{
				printf("Entramos > 3 elementos stack\n");
				push_stacks(&a, &b);
			}
		}
	}
	return (stack_free(&a), 0);
}
