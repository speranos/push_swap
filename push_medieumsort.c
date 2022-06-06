/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_medieumsort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 00:11:15 by aoueldma          #+#    #+#             */
/*   Updated: 2022/06/01 00:52:40 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_min(t_stack *stack)
{
	int	tmp;
	int	i;

	tmp = stack->array[stack->top];
	i = 0;
	while (i < stack->len)
	{
		if (stack->array[i] < tmp)
		{
			tmp = stack->array[i--];
			i = 0;
		}
		i++;
	}
	return (tmp);
}

void	ft_medieumsort(t_stack *stacka, t_stack *stackb)
{
	int	tmp;

	while (stacka->top > 2)
	{
		tmp = ft_min(stacka);
		while (stacka->array[stacka->top] != tmp)
			ft_ra(stacka);
		push (stackb, pop(stacka), 'b');
		stacka->len--;
		stackb->len++;
	}
	ft_smallsort(stacka);
	while (stackb->top >= 0)
		push (stacka, pop(stackb), 'a');
}
