/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_mysort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 00:40:38 by aoueldma          #+#    #+#             */
/*   Updated: 2022/06/01 00:44:32 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_mysortcheck(t_stack *stack)
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

int	ft_mymin(t_stack *stack)
{
	int	tmp;
	int	i;

	tmp = stack->array[stack->top];
	i = stack->last;
	while (i <= stack->top)
	{
		if (stack->array[i] < tmp)
		{
			tmp = stack->array[i];
			i = stack->last;
		}
		i++;
	}
	return (tmp);
}

void	ft_myra(t_stack *stack)
{
	int	tmp;
	int	i;

	tmp = stack->array[stack->top];
	i = stack->top;
	while (i >= stack->last)
	{
		stack->array[i] = stack->array[i - 1];
		i--;
	}
	stack->array[stack->last] = tmp;
}

void	ft_mysort(t_stack *stacka, t_stack *stackb)
{
	int	tmp;
	int	toptmp;

	toptmp = stacka->top;
	while (stackb->top < toptmp)
	{
		tmp = ft_mymin(stacka);
		while (stacka->array[stacka->top] != tmp)
			stacka->top--;
		ft_myra(stacka);
		push(stackb, stacka->array[stacka->last], 'c');
		stacka->top = toptmp;
		stacka->last++;
	}
	stacka->top = -1;
	while (stackb->top > -1)
		push(stacka, pop(stackb), 'c');
}
