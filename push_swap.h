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
	int len;
	int last;
} t_stack;
int	ft_atoi(char *str);
int	ft_putstr(char *str);
int	ft_sortcheck(t_stack *stack);
void	ft_smallsort(t_stack *stack);
void	ft_medieumsort(int ac, t_stack *stacka, t_stack *stackb);
void	ft_largesort(t_stack *stacka, t_stack *stackb);
void	push(t_stack *stack, int nbr);
int pop(t_stack *stack);
void	ft_sa(t_stack *stack);
void	ft_ra(t_stack *stack);
void	ft_rra(t_stack *stack);
void	ft_myra(t_stack *stack);

#endif