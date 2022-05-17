#include "puch_swap.h"

int isEmpty(t_stack* stack)
{
    return stack->top == -1;
}

int isFull(t_stack* stack)
{
    return stack->top == stack->len;
}


void	push(t_stack *stack, int nbr)
{
	// printf("yooooo : %d\n", nbr);
	if (isFull(stack))
        return ;
	stack->array[++stack->top] = nbr;
}

int pop(t_stack *stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}

// int	ft_alloc(char   *str, int ac)
// {
    // int     i;
    // int     a;
    // char    *pass;

    // i = 0;
    // a = 0;
    // pass = malloc(sizeof(char) * ft_strlen(str) + 1);
    // while (str[i])
	// 	pass[a++] = str[i++];
	// pass[a] = '\0';
	// return (ft_atoi(pass));
// }

int	ft_sortcheck(int ac, t_stack *stack)
{
	int i;
	int j;

	i = 0;
	while (i < stack->len)
	{
		j = i + 1;
		while (j < stack->len)
		{
			if (stack->array[i] < stack->array[j])
				return (0);
			j++;
		}
		i++;
	}
	return(1);
}

int	*ft_sizeofsort(int ac, t_stack *stacka, t_stack *stackb)
{
	//int	i;

	//i = ac - 2;
	if (ac == 4 || ac == 3)
		return (ft_Ssort(stacka));
	else if (ac >= 5 && ac <= 11)
		return (ft_Msort(stacka->len, stacka, stackb));
	// else if(ac > 6 && ac <= 100)
	// 	ft_Lsort(stacka, stackb);
	// else if (ac > 100)
	// 	ft_XLsort(stacka,stackb);
	return (stacka->array);

}
int ft_free(t_stack *stacka, t_stack *stackb)
{
	free(stacka->array);
	free(stackb->array);
	return (0);
}

int main(int ac, char **av)
{
	//int	*stacka;
    int	i;
	//int	*stackb;
	t_stack	stacka;
	t_stack	stackb;

	if (ac < 2)
		return (-1);
	if (ft_checker(ac, av) == 1)
		return (ft_putstr("ERROR"));
	stacka.len = ac - 1;
	stacka.top = -1;
	stackb.top = -1;
	stackb.len = ac - 1;
	stacka.array = malloc(sizeof(int) * stacka.len);
	stackb.array = malloc(sizeof(int) * stackb.len);
	i = stacka.len;
	while (i > 0)
	{
		push(&stacka, ft_atoi(av[i]));
		// push(&stacka, ft_alloc(av[i], ac));
		i--;
	}
	if (ft_sortcheck(ac - 2, &stacka) == 1)
		return (ft_free(&stacka, &stackb));
	stacka.array = ft_sizeofsort(ac, &stacka, &stackb);
//	stacka.array = trachtest(&stacka, &stackb);
	// i = ac - 2;
	// while (i >= 0)
	// {
	// 	printf("stack === %d\n", stacka.array[i]);
	// 	i--;
	// }
 }