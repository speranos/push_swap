#include  <stdio.h>
#include <unistd.h>
#include <stdlib.h>


static const char	*re(const char	*str)
{
	int					i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' )
		i++;
	return (&str[i]);
}

int	ft_atoi(char *str)
{
	int					i;
	unsigned long int	r;
	int					s;
	const char			*st;

	st = re(str);
	i = 0;
	s = 1;
	r = 0;
	if (st[i] == '-' || st[i] == '+')
	{
		if (st[i] == '-')
			s = s * -1;
		i++;
	}
	while (st[i] && st[i] >= '0' && st[i] <= '9')
	{
		r = r * 10 + (st[i] - 48);
		i++;
		if (r > 9223372036854775807 && (s == 1))
			return (-1);
		if (r > 9223372036854775807 && (s == -1))
			return (0);
	}
	free(str);
	return (r * s);
}

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);    
}

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int    ft_putstr(char *str)
{
    int     i;
    
	i = 0;
    while (str[i])
		ft_putchar(str[i++]);
    return (i);
}

void	push(int	*stack, int nbr)
{
	int top;
	// int	*stack;
	//int	i;
	static int i;
	//i = 0;
			stack[i++] = nbr;
			//i++;

}

int	ft_alloc(char   *str, int ac)
{
    int     i;
    int     a;
    char    *pass;

    i = 0;
    a = 0;
    pass = malloc(sizeof(char) * ft_strlen(str) + 1);
    while (str[i])
		pass[a++] = str[i++];
	pass[a] = '\0';
	return (ft_atoi(pass));
}

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

int	*ft_swap(int i, int *stack)
{
	int	tmp1;
	int	tmp2;

	tmp1 = stack[i];
	tmp2 = stack[i - 1];
	stack[i - 1] = tmp1;
	stack[i] = tmp2;
return (stack);
}

// int	*ft_rot(int i, int *stack)
// {
	
// }
int	ft_sortcheck(int ac, int *stack)
{
	int i;

	i = stack[ac];
	//printf("\ni ===== %d",i); 
	while (stack[ac])
	{
		if (stack[ac] < i)
			return (1);
		ac--;
	}
	return(0);
}

int	*ft_Ssort(int ac, int *stack, int *stackb)
{
	if (ft_sortcheck(ac - 2,ft_swap(ac - 2, stack)) == 0)
	{
		stack = ft_swap(ac - 2, stack);
		ft_putstr("sa\n");
		return (stack);
	}
	return (stack);
	//if ()
}

int	*ft_sizeofsort(int ac, int *stacka, int *stackb)
{
	if (ac == 4)
		return (ft_Ssort(ac - 2,  stacka, stackb));
	// else if (ac == 6)
	// 	ft_Msort(stacka, stackb);
	// else if(ac > 6 && ac <= 100)
	// 	ft_Lsort(stacka, stackb);
	// else if (ac > 100)
	// 	ft_XLsort(stacka,stackb);
	return (stacka);

}

int main(int ac, char **av)
{
	int	aci;
	int	*stacka;
    int	i;
	int	*stackb;

    aci = ac - 1;
	i = 1;
	if (ac < 2)
		return (-1);
	if (ft_checker(ac, av) == 1)
		return (ft_putstr("ERROR"));
	stacka = malloc(sizeof(int) * ac);
	stackb = malloc(sizeof(int) * ac);
	while (i < ac)
	{
		push(stacka, ft_alloc(av[aci--], ac));
		i++;
	}
	stacka[ac - 1] = '\0';
	if (ft_sortcheck(ac - 2, stacka) == 0)
		return (0);
	ft_sizeofsort(ac, stacka, stackb);
	stacka = ft_swap(ac - 2, stacka);
	i = ac - 2;
	while (ac != 1)
	{
		printf("stack === %d\n",stacka[i--]);
		ac--;
	}
}