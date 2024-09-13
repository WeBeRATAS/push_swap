/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:32:49 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/09/13 17:34:04 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	put_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	check_limits(long n)
{
	if (n > INT_MAX || n < INT_MIN)
		put_error();
}

int	isduplicate(int i, char **av)
{
	int	j;

	j = 1;
	while (j < i)
	{
		if (ft_atol(av[i]) == ft_atol(av[j]))
			put_error();
		j++;
	}
	return (0);
}

void	check_args(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '\0')
			put_error();
		ft_isadigit(av[i]);
		isduplicate(i, av);
		check_limits(ft_atol(av[i]));
		i++;
	}
	return (0);
}
