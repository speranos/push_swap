/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 00:07:55 by aoueldma          #+#    #+#             */
/*   Updated: 2022/06/01 00:50:20 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	push(t_stack *stack, int nbr, char c)
{
	stack->array[++stack->top] = nbr;
	if (c == 'a')
		ft_putstr("pa\n");
	else if (c == 'b')
		ft_putstr("pb\n");
}

int	pop(t_stack *stack)
{
	return (stack->array[stack->top--]);
}

void	ft_sa(t_stack *stack)
{
	int	tmp2;

	tmp2 = stack->array[stack->top - 1];
	stack->array[stack->top - 1] = stack->array[stack->top];
	stack->array[stack->top] = tmp2;
	ft_putstr("sa\n");
}

void	ft_ra(t_stack *stack)
{
	int	tmp;
	int	i;

	tmp = stack->array[stack->top];
	i = stack->top;
	while (i >= 0)
	{
		stack->array[i] = stack->array[i - 1];
		i--;
	}
	stack->array[0] = tmp;
	ft_putstr("ra\n");
}

void	ft_rra(t_stack *stack)
{
	int	tmp;
	int	i;

	i = 1;
	tmp = stack->array[0];
	while (i <= stack->top)
	{
		stack->array[i - 1] = stack->array[i];
		i++;
	}
	stack->array[stack->top] = tmp;
	ft_putstr("rra\n");
}
