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
		&& stack->array[stack->top]  > stack->array[0])
		ft_rra(stack);
}

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

void	ft_medieumsort(int ac, t_stack *stacka, t_stack *stackb)
{
	int	tmp;

	while (stacka->top > 2)
	{
		tmp = ft_min(stacka);
		while (stacka->array[stacka->top] != tmp)
			ft_ra(stacka);
		push (stackb, pop(stacka));
		stacka->len--;
		stackb->len++;
		ft_putstr("pb\n");
	}
	ft_smallsort(stacka);
	while (stackb->top > 0)
	{
		push (stacka, pop(stackb));
		ft_putstr("pa");
	}
}

int	ft_mysortcheck(t_stack *stack)
{
	int i;
	int j;

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
	return(1);
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

void	ft_mysort(t_stack *stacka, t_stack *stackb)
{
	int tmp;
	int toptmp;
	int	i;

	toptmp = stacka->top;
	while (ft_mysortcheck(stacka) != 1)
	{
		tmp = ft_mymin(stacka);
		while (stacka->array[stacka->top] != tmp)
			stacka->top--;
		ft_myra(stacka);
		push(stackb, stacka->array[stacka->last]);
		stacka->top = toptmp;
		stacka->last++;
	}
	push(stackb, stacka->array[stacka->top]);
	stacka->top = -1;
	while (stackb->top > -1)
	{
		push(stacka,pop(stackb));
	}
}

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
			{
				push(stackb,pop(stacka));
				ft_putstr("pb\n");
			}
			i++;
		}
		while (stackb->top != -1)
		{
			push(stacka,pop(stackb));
			ft_putstr("pa\n");
		}
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
	int	i;
	int	tmp;

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
				break;
			}
			stacka->top--;
		}
		toradix.top--;
		stacka->top = tmp;
	}
	toradix.top = tmp;
	ft_radixsort(&toradix,stackb);
	free (toradix.array);
}