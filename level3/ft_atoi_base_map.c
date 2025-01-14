#include <unistd.h>
#include <stdio.h>

int	ft_atoi_base(const char *str, int str_base)
{
    int	res = 0;
	int	sign = 1;
	int	i = 0;
	int n;
	// Cadena con los valores de los dígitos de base 16
    const char *digits = "0123456789ABCDEF";
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (str[i])
	{
		// Encuentra el valor del carácter en la cadena digits
		const char *ptr;
		ptr = digits;
		if (str[i] == '-')
			str++;
		while (*ptr && *ptr != str[i]) // Busca el carácter en la cadena digits
			ptr++;
		// Si el carácter no está en la cadena 'digits', termina
		if (*ptr == '\0')
			break;
		n = ptr - digits;  // Calcula el valor del carácter (0-15)
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