#include <unistd.h>

int    max(int* tab, unsigned int len)
{
    int    max_value;
    int    i;
    if(len > 0)
    {
        max_value = tab[0];
        i = 1;
        while(i < len)
        {
            if(tab[i] > max_value)
                max_value = tab[i];
            i++;
        }
        return (max_value);
    }
    return (0);
}