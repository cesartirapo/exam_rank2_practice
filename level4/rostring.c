#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void    rostring(char *s)
{
    int i = 0;
    int j;
    int first_word = 0;
    int new_word = 0;
    while(s[i])
    {
        if(s[i] >= 33 && s[i] <= 126)
        {
            if(!first_word)
            {
                j = i;
                first_word = 1;
                while(s[i] >= 33 && s[i] <= 126)
                    i++;
            }
            else
            {
                if(new_word)
                    write(1, " ", 1);
                while(s[i] >= 33 && s[i] <= 126)
                {
                    write(1, &s[i], 1);
                    i++;
                }
                new_word = 1;
            }
        }
        else
            i++;
    }
    if(first_word)
    {
        if(new_word)
            write(1,  " ", 1);
        while(s[j] >= 33 && s[j] <= 126)
        {
            write(1, &s[j], 1);
            j++;
        }
    }
}

int	main(int ac, char **av)
{
	if(ac == 2)
	{
        rostring(av[1]);
        write(1, "\n", 1);
    }
	else
		write(1, "\n", 1);
}