#include <stdio.h>

int	    is_power_of_2(unsigned int n)
{
    while(n >= 2 && n % 2 == 0)
    {
        n = n / 2;
    }
    if(n == 1)
        return (1);
    else
        return (0);
}

int    main(int argc, char **argv)
{
    printf("%d\n", is_power_of_2(4));  // Imprime 1
    printf("%d\n", is_power_of_2(5));  // Imprime 0
    printf("%d\n", is_power_of_2(6));  // Imprime 0
}