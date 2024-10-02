/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:52:03 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/10/02 16:23:13 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*free_av(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
	return (NULL);
}

void	ft_param(int ac, char **av)
{
	if (ac == 1 || (ac == 2 && !av[1][0]))
	{
		if (ac == 2)
			put_error();
		exit(EXIT_FAILURE);
	}
}

char	**prueba_split(char **av, int *flag)
{
	*flag = 1;
	return (ft_split(av[1], ' '));
}

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				flag;

	a = NULL;
	b = NULL;
	flag = 0;
	ft_param(ac, av);
	if (ac == 2)
		av = prueba_split(av, &flag);
	check_args(ac, av);
	stack_init(&a, av + 1);
	if (!is_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	if (flag)
		av = free_av(av);
	return (stack_free(&a), stack_free(&b), 0);
}
