/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:52:03 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/09/17 18:53:23 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		exit(EXIT_FAILURE);
	if (ac >= 2)
	{
		printf("Control 1\n");
		if (check_args(ac, av))
			return (put_error());
	/*av = ft_split(av[1], ' ');
	if (!av)
	{
		put_error();
		return (1);
	}*/
		printf("Control 2 despues revisar argumentos check\n");
		stack_init(&a, av);
		printf("Control 4 despues de stack init\n");
		if (!is_sorted(a))
		{
			printf("Control 5 dentro de if is_sorted\n");
			if (stack_len(a) == 2)
				sa(&a, false);
			else if (stack_len(a) == 3)
				sort_three(&a);
			else if (stack_len(a) <= 5)
				sort_five(&a, &b);
			else
				sort_stacks(&a, &b);
		}
		return (stack_free(&a), 0);
	}
	return (0);
}
