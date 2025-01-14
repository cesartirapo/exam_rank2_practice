#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

unsigned int    lcm(unsigned int n, unsigned int n2)
{
    unsigned int g;
    if(n == 0 || n2 == 0)
    	return (0);
    if(n > n2)
        g = n;
    else
        g = n2;
    while(1)
    {
        if((g % n == 0) && (g % n2 == 0))
            return (g);
        g++;
    }
}

int main(int ac, char **av)
{
    if (ac == 3)
        {
            unsigned int m = lcm(atoi(av[1]), atoi(av[2]));
            printf("LCM: %u\n", m);
        }
    else
        write(1, "\n", 1);
    return (0);
}