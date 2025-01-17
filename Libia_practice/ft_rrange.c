#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	*ft_rrange(int start, int end)
{
	int i = 0;
	int *number;
	int len = 0;
	if (end > start)
		len = end - start;
	else
		len = start - end;		
	number = malloc((end - start + 1) * sizeof(int));
	if(!number)
		return NULL;
	if(end > start)
	{
		while(i < (len + 1))
			{
				number[i++] = end--;
			}
	}		
	else
	{
		while (i < (len + 1))
		{
			number[i++] = start--;
		}
	}
		return number;
}

int main (int ac, char **av)
{
	int *number;
	if(ac == 3)
	{	
		number = ft_rrange(atoi(av[1]), atoi(av[2]));
		printf("%d\n", number);
		free(number);
	}
	else
		write(1, "\n", 1);
}
