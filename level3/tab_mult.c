#include <unistd.h>

void	ft_putnbr(int n)
{
    if (n >= 10)
        ft_putnbr(n / 10);
    char c = n % 10 + '0';
    write(1, &c, 1);
}

int	ft_atoi(char *str)
{
	int i = 0;
	int sign = 1;
	int result = 0;
	while(str[i])
	{
		if(str[i] == '-')
			sign *= -1;
		else if(str[i] >= '0' && str[i] <= '9')
		{
			result = result * 10 + (str[i] - '0');
		}
		i++;
	}
	return (sign * result);
}

int	main(int ac, char **av)
{
    if (ac == 2)
    {
        int n = ft_atoi(av[1]);  // Usamos atoi para convertir el argumento a entero
        for (int i = 1; i <= 9; i++)
        {
            ft_putnbr(i);
            write(1, " x ", 3);
            ft_putnbr(n);
            write(1, " = ", 3);
            ft_putnbr(i * n);
            write(1, "\n", 1);
        }
    }
    else
    {
        write(1, "\n", 1);
    }
    return (0);
}
