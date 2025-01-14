#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void    rev_wstr(char *s)
{
    int i = 0;
    int j;
    int first = 0;
    while(s[i])
        i++;
    while(i >= 0)
    {
        j = i;
        if(s[i - 1] == ' ' || s[i - 1] == '\t' || i == 0)
        {
          if(first)
            {
              write(1, " ", 1);
            }
            while(s[j] >= 33 && s[j] <= 126)
            {
                write(1, &s[j], 1);
                j++;
            }
            first = 1;
        }
        i--;
    }
}

int	main(int ac, char **av)
{
	if(ac == 2)
	{
        rev_wstr(av[1]);
        write(1, "\n", 1);
    }
	else
		write(1, "\n", 1);
}