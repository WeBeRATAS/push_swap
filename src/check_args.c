/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:32:49 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/09/17 13:12:47 by rbuitrag         ###   ########.fr       */
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

int	ft_atol(const char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' \
			|| *str == '\v' || *str == '\f' || *str == '\r' || *str == '0')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
		res = res * 10 + (*str++ - '0');
	return (res * sign);
}

void	check_args(int ac, char **av)
{
	int		i;
	long	n;

	i = 1;
	n = 0;
	while (i < ac)
	{
		if (av[i][0] == '\0')
			put_error();
		n = ft_atol(av[i]);
		ft_isdigit((int)n);
		isduplicate(i, av);
		check_limits(n);
		i++;
	}
}
