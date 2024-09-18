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

int	ft_isnum(char *s)
{
	int	i;

	i = 0;
	if ((s[i] == '-' || s[i] == '+') && (s[i + 1] == '\0'))
		put_error();
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			i++;
		else
			put_error();
	}
	return (1);
}

void	ft_check_limits(long n)
{
	if (n > INT_MAX || n < INT_MIN)
		put_error();
}

int	ft_isduplicate(int i, char **av)
{
	int	j;

	j = 1;
	while (j < i)
	{
		if (ft_atol(av[j]) == ft_atol(av[i]))
			put_error();
		j++;
	}
	return (0);
}

long	ft_atol(const char *str)
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

int	check_args(int ac, char **av)
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
		ft_isnum(av[i]);
		ft_isduplicate(i, av);
		ft_check_limits(n);
		printf("Control 3.1\n");
		i++;
	}
	return (0);
}
