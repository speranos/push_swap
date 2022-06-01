/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 00:01:52 by aoueldma          #+#    #+#             */
/*   Updated: 2022/06/01 00:40:25 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_radixsort(t_stack *stacka, t_stack *stackb)
{
	int	tmp;
	int	i;
	int	n;

	n = 0;
	while (ft_sortcheck(stacka) != 1)
	{
		i = 0;
		while (i < stacka->len)
		{
			tmp = stacka->array[stacka->top];
			if ((tmp >> n & 1) == 1)
				ft_ra(stacka);
			else
				push(stackb, pop(stacka), 'b');
			i++;
		}
		while (stackb->top != -1)
			push(stacka, pop(stackb), 'a');
		n++;
	}
}

void	ft_allocsort(t_stack *toradix, t_stack *stacka)
{
	int	tmp;

	tmp = stacka->top;
	toradix->array = malloc(sizeof(int) * stacka->len);
	toradix->top = tmp;
	toradix->len = stacka->len;
	while (stacka->top != -1)
		toradix->array[toradix->top--] = stacka->array[stacka->top--];
	toradix->top = tmp;
	stacka->top = tmp;
}

void	ft_largesort(t_stack *stacka, t_stack *stackb)
{
	t_stack	toradix;
	int		tmp;

	tmp = stacka->top;
	ft_allocsort(&toradix, stacka);
	ft_mysort(stacka, stackb);
	while (toradix.top != -1)
	{
		while (stacka->top != -1)
		{
			if (stacka->array[stacka->top] == toradix.array[toradix.top])
			{
				toradix.array[toradix.top] = stacka->top;
				break ;
			}
			stacka->top--;
		}
		toradix.top--;
		stacka->top = tmp;
	}
	toradix.top = tmp;
	ft_radixsort(&toradix, stackb);
	free (toradix.array);
}
