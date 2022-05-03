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
    {
		ft_putchar(str[i++]);
    }
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
    {
        pass[a++] = str[i++];
    }
    pass[a] = '\0';
	ft_putstr(pass);
	free(pass);

}

int main(int ac, char **av)
{
    int aci;
    int avi;
    int i = 1;

    aci = 1;
    avi = 0;
   // while (i < ac)
   //printf("%s\n",av[2]);
   while (i < ac)
   {
   	ft_alloc(av[aci++]);
	   i++;
	}
   // {
        //while (av[avi])
        //{
            //printf("%s\n",av[avi]);
            //avi++;
        //}
        //ac--;
        //i++;
    //}
}