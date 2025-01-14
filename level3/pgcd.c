#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

unsigned int    pgcd(unsigned int n, unsigned int n2)
{
    unsigned int g;
    if(n > n2)
        g = n2;
    else
        g = n;
    while(1)
    {
        if((n % g == 0) && (n2 % g == 0))
            return (g);
        g--;
    }
}

int main(int ac, char **av)
{
    if (ac == 3)
        {
            int n1 = atoi(av[1]);
            int n2 = atoi(av[2]);
            if(n1 <= 0 || n2 <= 0)
            {
                write(1, "\n", 1); // Si hay números negativos o cero, no hacemos el cálculo
                return (0);
            }
            unsigned int m = pgcd(n1, n2);
            printf("HCD: %u\n", m);
        }
    else
        write(1, "\n", 1);
    return (0);
}