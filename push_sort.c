#include "puch_swap.h"

int ft_checker(int ac, char **str)
{
	int i;
	int	a;

	i = 1;
	a = 0;
	while (i < ac)
	{
		while (str[i][a])
		{
			if (str[i][a] == '-')
				a++;
			if (str[i][a] < 48 || str[i][a] > 57)
				return (1);
			a++;
		}
		a = 0;
		i++;
	}
	return (0);
}

int	*ft_sa(t_stack *stack)
{
	int	tmp2;

	tmp2 = stack->array[stack->top - 1];
	stack->array[stack->top - 1] = stack->array[stack->top];
	stack->array[stack->top] = tmp2;
	ft_putstr("sa\n");
return (stack->array);
}

int	*ft_ra(t_stack *stack)
{
	int	tmp1;
	int i;

	tmp1 = stack->array[stack->top];
	i = stack->top;	
	while (i >= 0)
	{
		stack->array[i] = stack->array[i - 1];
		i--;
	}
	stack->array[0] = tmp1;
	ft_putstr("ra\n");
	return (stack->array);
}

int	*ft_rra(t_stack *stack)
{
	int	tmp1;
	int	i;

	i = 1;
	tmp1 = stack->array[0];
	while (i <= stack->top)
	{
		stack->array[i - 1] = stack->array[i];
		i++;
	}
	stack->array[stack->top] = tmp1;
	ft_putstr("rra\n");
	return (stack->array);
}

int	*ft_Ssort(t_stack *stack)
{
	if (stack->array[0] > stack->array[stack->top]
		&& stack->array[stack->top - 1] < stack->array[stack->top])
		stack->array = ft_sa(stack);
	else if (stack->array[stack->top] > stack->array[0]
		&& stack->array[stack->top - 1] > stack->array [0]
		&& stack->array[stack->top - 1] < stack->array[stack->top])
	{
		stack->array = ft_sa(stack);
		stack->array = ft_rra(stack);
	}
	else if (stack->array[stack->top] > stack->array[0]
		&& stack->array[stack->top] > stack->array[stack->top - 1])
		stack->array = ft_ra(stack);
	else if (stack->array[stack->top] < stack->array[0]
		&& stack->array[0] < stack->array[stack->top - 1])
	{
		stack->array = ft_sa(stack);
		stack->array = ft_ra(stack);
	}
	else if (stack->array[0] < stack->array[stack->top - 1]
		&& stack->array[stack->top]  > stack->array[0])
		stack->array = ft_rra(stack);
	return(stack->array);
}

int	tesssst(t_stack *stack)
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

int	*ft_Msort(int ac, t_stack *stacka, t_stack *stackb)
{
	int	tmp2;

	while (stacka->top > 2)
	{
		tmp2 = tesssst(stacka);
		while (stacka->array[stacka->top] != tmp2)
			ft_ra(stacka);
		push (stackb, pop(stacka));
		stacka->len--;
		stackb->len++;
		ft_putstr("pb\n");
	}
	stacka->array = ft_Ssort(stacka);
	while (stackb->top > 0)
	{
		push (stacka, pop(stackb));
	}
	return (stacka->array);  
}

// int	*trachtest(t_stack *stacka, t_stack  *stackb)
// {
// 		printf("%d\n",tesssst(stacka));
// 	return (stacka->array);
// }