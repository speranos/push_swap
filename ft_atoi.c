/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 00:50:32 by aoueldma          #+#    #+#             */
/*   Updated: 2022/06/06 23:38:28 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

char	*re(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' )
		i++;
	return (&str[i]);
}

int	ft_max_check(long num, int s)
{
	if ((num * s) > 2147483647)
	{
		ft_putstr("ERROR...YOU' VE REACHED THE MAX_INT!!!\n");
		return (1);
	}
	if ((num * s) < -2147483648)
	{
		ft_putstr("ERROR...YOU' VE REACHED THE MIN_INT!!!\n");
		return (1);
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int			i;
	long		r;
	int			s;
	const char	*st;

	st = re(str);
	i = 0;
	s = 1;
	r = 0;
	if (st[i] == '-' || st[i] == '+')
	{
		if (st[i] == '-')
			s = s * -1;
		i++;
	}
	while (st[i] && st[i] >= '0' && st[i] <= '9')
	{
		r = r * 10 + (st[i] - 48);
		i++;
	}
	if (ft_max_check(r, s) == 1)
		exit(1);
	return (r * s);
}

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
	return (i);
}
