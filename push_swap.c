#include  <stdio.h>
#include <unistd.h>
#include <stdlib.h>

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

void    ft_alloc(char   *str)
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
	/*Push to stack*/
    ft_putstr(pass);
	printf("\n");
	free(pass);
}

int ft_checker(int ac, char **str)
{
    //printf("dakhla:%s",str);
    int i;
	int	a;

    i = 1;
	a = 0;
	while (i < ac)
	{
    	while (str[i][a])
    	{
			// printf("str >>>> %s\n",str[i]);
        	if (str[i][a] < 48 || str[i][a] > 57)
				return (1);
			//printf("str >>>> %s\n",str[i]);
			//printf("CC >>>> %c\n",str[i][a]);
        	a++;
    	}
		a = 0;
		i++;
	}
	return (0);
}

int main(int ac, char **av)
{
    int aci;
    int avi;
    int i = 1;

    aci = 1;
    avi = 0;
	if (ac < 2)
		return (-1);
	if (ft_checker(ac, av) == 1)
		return (ft_putstr("ERROR"));
   while (i < ac)
	{
		// if (ft_checker(av[aci]) == 1)
		// 	return (ft_putstr("ERROR"));
		ft_alloc(av[aci++]);
	   i++;
	}
}