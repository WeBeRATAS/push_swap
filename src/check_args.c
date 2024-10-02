/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:32:49 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/10/02 13:27:14 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_isnum(char *s)
{
	int	i;

	i = 0;
	if (!s)
		put_error();
	if (((s[i] == '-' || s[i] == '+') && (s[i + 1] == '\0')) \
	|| ((s[i] == '-' || s[i] == '+') && (s[i + 1] == '0')))
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
	return (1);
}

long	ft_atol(char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	if (!str)
		put_error();
	while (*str == ' ' || (*str >= 9 && *str <= 13) || *str == '0')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
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
		if (!av || !(av[i][0]))
			put_error();
		ft_isnum(av[i]);
		n = ft_atol(av[i]);
		ft_check_limits(n);
		ft_isduplicate(i, av);
		i++;
	}
	return (0);
}
