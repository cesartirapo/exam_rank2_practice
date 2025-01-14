#include <stdio.h>
#include <stdlib.h>

int    numlen(int   n)
{
    int len;
    len = 0;
    if(n == 0)
        return (1);
    else if (n == -2147483648)
    {
        return (10);
    }
    else if(n < 0)
        n = -n;
    while(n > 0)
    {
        n = n / 10;
        len++;
    }
    return len;
}

char	*ft_itoa(int n)
{
    int i;
    i = 0;
    int len = (numlen(n));
    if(n < 0)
        i++;
    len = len + i;
    char    *str = (char *) malloc((len + 1) * sizeof(char));
    if(str == NULL)
        return NULL;
    if (n == -2147483648)
    {
        str[0] = '-';
        str[1] = '2';
        n = 147483648;  // El resto del número después de "2"
        i++;
    }
    else if(n < 0)
        {
            str[0] = '-';
            n = -n;
        }
    str[len] = '\0';
    while(len - 1 >= i)
    {
        str[len - 1] = n % 10 + '0';
        n /= 10;
        len--;
    }
    return str;
}

int	main(int ac, char **av)
{
	if(ac == 2)
	{
		int	n = atoi(av[1]);
		char *str = ft_itoa(n);  // Guarda el resultado de ft_itoa
		printf("%s\n", str);     // Imprime el string
		free(str);               // Libera la memoria asignada por ft_itoa
	}
	else
		printf("\n");
}