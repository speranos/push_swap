/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 00:45:01 by aoueldma          #+#    #+#             */
/*   Updated: 2022/06/01 00:48:55 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include  <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int	top;
	int	*array;
	int	len;
	int	last;
}	t_stack;
int		ft_atoi(char *str);
int		ft_putstr(char *str);
int		ft_sortcheck(t_stack *stack);
void	ft_smallsort(t_stack *stack);
void	ft_medieumsort(t_stack *stacka, t_stack *stackb);
void	ft_largesort(t_stack *stacka, t_stack *stackb);
void	push(t_stack *stack, int nbr, char c);
int		pop(t_stack *stack);
void	ft_sa(t_stack *stack);
void	ft_ra(t_stack *stack);
void	ft_rra(t_stack *stack);
void	ft_myra(t_stack *stack);
void	ft_mysort(t_stack *stacka, t_stack *stackb);
int		ft_checker(int ac, char **str);
int		ft_duplicate(int ac, char **str);
void	ft_radixsort(t_stack *stacka, t_stack *stackb);
#endif
