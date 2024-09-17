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
	{
		if (ac == 2)
			put_error();
		return (0);
	}
	printf("Control 1\n");
	av = ft_split(av[1], ' ');
	printf("Control 2 despues split texto\n");
	check_args(ac, av);
	printf("Control 3 despues revisar argumentos check\n");
	stack_init_a(&a, av + 1);
	printf("Control 4 despues de stack init\n");
	if (!is_sorted(a))
	printf("Control 5 despues de esta ordenado\n");
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else if (stack_len(a) > 3)
			sort_stacks(&a, &b);
	}
	printf("Control 6 no entra en bucle de esta ordenado\n");
	return (stack_free(&a), 0);
}
