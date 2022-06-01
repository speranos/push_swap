/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 00:16:21 by aoueldma          #+#    #+#             */
/*   Updated: 2022/06/01 00:20:01 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_checker(int ac, char **str)
{
	int	i;
	int	a;

	i = 1;
	a = 0;
	while (i < ac)
	{
		while (str[i][a])
		{
			if (str[i][a] == '-' || str[i][a] == '+')
				a++;
			if (str[i][a] < 48 || str[i][a] > 57)
				return (1);
			a++;
		}
		a = 0;
		i++;
	}
	return (0);
}

int	ft_duplicate(int ac, char **str)
{
	int	a;
	int	i;
	int	tmp;
	int	r;

	a = ac - 1;
	i = a;
	r = 0;
	while (i > 0)
	{
		tmp = ft_atoi(str[i]);
		while (a > 0)
		{
			if (tmp == ft_atoi(str[a]))
				r++;
			a--;
		}
		if (r > 1)
			return (1);
		a = ac - 1;
		r = 0;
		i--;
	}
	return (0);
}
