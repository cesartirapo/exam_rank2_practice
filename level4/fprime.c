#include <stdio.h>
#include <stdlib.h>

void	fprime(int n)
{
	int i = 2;
    int first = 1;

    if (n == 1) 
	{
        printf("1");
        return;
    }

    while (i * i <= n) 
	{
        while (n % i == 0) 
		{
            if (!first) 
			{
                printf("*");
            }
            printf("%d", i);
            n /= i;
            first = 0;
        }
        i++;
    }

    if (n > 1) 
	{
        if (!first) 
		{
            printf("*");
        }
        printf("%d", n);
    }
}

int	main(int ac, char **av)
{
	if(ac == 2)
	{
		int	n = atoi(av[1]);
		if(n > 1)
			fprime(n);
		printf("\n");
	}
	else
		printf("\n");
}