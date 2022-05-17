#ifndef PUCH_SWAP_H
# define PUCH_SWAP_H
# include  <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int	top;
	int	*array;
	int len;
} t_stack; 
int             ft_atoi(char *str);
int ft_strlen(char *str);
int	ft_putchar(char c);
int  ft_putstr(char *str);
// int	ft_alloc(char   *str, int ac);
int ft_checker(int ac, char **str);
int	*ft_sa(t_stack *stack);
int	*ft_ra(t_stack *stack);
int	*ft_rra(t_stack *stack);
int	ft_sortcheck(int ac, t_stack *stack);
int	*ft_Ssort(t_stack *stack);
//int	*ft_Msort(int i, int *stacka, int *stackb);
int	*ft_sizeofsort(int ac, t_stack *stacka, t_stack *stackb);
int ft_free(t_stack *stacka, t_stack *stackb);
int	*ft_Msort(int ac, t_stack *stacka, t_stack *stackb);
void	push(t_stack *stack, int nbr);
int isEmpty(t_stack* stack);
int isFull(t_stack* stack);
int pop(t_stack *stack);
int	*trachtest(t_stack *stacka, t_stack  *stackb);

#endif