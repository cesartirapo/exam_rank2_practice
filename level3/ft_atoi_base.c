#include <unistd.h>
#include <stdio.h>

int	ft_atoi_base(const char *str, int str_base)
{
    int	res = 0;
	int	sign = 1;
	int	i = 0;
	int n;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (str[i])
	{
        if (str[i] == '-')
            i++;
		if (str[i] >= '0' && str[i] <= '9')
			n = str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			n = str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')
			n = str[i] - 'A' + 10;
		else
			break;
		res = res * str_base + n;
		i++;
	}
	return (res * sign);
}

int main(int argc, char **argv)
{
    if (argc == 3)
    {
        int base = ft_atoi_base(argv[2], 10); // Convertir el tercer argumento a entero
        printf("El número es: %d\n", ft_atoi_base(argv[1], base));
    }
    else
        write(1, "\n", 1);
    return (0);
}