/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 23:38:43 by aoueldma          #+#    #+#             */
/*   Updated: 2022/06/06 23:39:18 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_radixsortcheck(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->len)
	{
		j = i + 1;
		while (j < stack->len)
		{
			if (stack->array[i] > stack->array[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_max_bit(t_stack *stacka)
{
	int	max_num;
	int	max_bit;

	max_bit = 0;
	max_num = stacka->array[0];
	while ((max_num >> max_bit) != 0)
		max_bit++;
	return (max_bit);
}

void	ft_bitshift(t_stack *stacka, t_stack *stackb, int n)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < stacka->len)
	{
		tmp = stacka->array[stacka->top];
		if ((tmp >> n & 1) == 1)
			push(stackb, pop(stacka), 'b');
		else
			ft_ra(stacka);
		i++;
	}
}

void	ft_radixsort(t_stack *stacka, t_stack *stackb, t_stack *stack)
{
	int	n;
	int	maxbit;

	n = 0;
	maxbit = ft_max_bit(stack);
	while (maxbit > 0)
	{
		ft_bitshift(stacka, stackb, n);
		while (stackb->top != -1)
			push(stacka, pop(stackb), 'a');
		n++;
		maxbit--;
		if (ft_radixsortcheck(stacka) == 1)
			break ;
	}
}
