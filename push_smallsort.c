/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puch_smallsort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 00:09:40 by aoueldma          #+#    #+#             */
/*   Updated: 2022/06/01 00:10:58 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_smallsort(t_stack *stack)
{
	if (stack->array[0] > stack->array[stack->top]
		&& stack->array[stack->top - 1] < stack->array[stack->top])
		ft_sa(stack);
	else if (stack->array[stack->top] > stack->array[0]
		&& stack->array[stack->top - 1] > stack->array [0]
		&& stack->array[stack->top - 1] < stack->array[stack->top])
	{
		ft_sa(stack);
		ft_rra(stack);
	}
	else if (stack->array[stack->top] > stack->array[0]
		&& stack->array[stack->top] > stack->array[stack->top - 1])
		ft_ra(stack);
	else if (stack->array[stack->top] < stack->array[0]
		&& stack->array[0] < stack->array[stack->top - 1])
	{
		ft_sa(stack);
		ft_ra(stack);
	}
	else if (stack->array[0] < stack->array[stack->top - 1]
		&& stack->array[stack->top] > stack->array[0])
		ft_rra(stack);
}
