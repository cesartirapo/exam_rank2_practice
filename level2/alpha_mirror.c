#include <unistd.h>
void    alpha_mirror(char *str)
{
    int    i;
    char    c;
    i = 0;
    while(str[i])
    {
        if(str[i] >= 'A' && str[i] <= 'M')
        {
            c = str[i] + (25 - ((str[i] - 'A') * 2));
            write(1, &c, 1);
        }
        else if(str[i] >= 'a' && str[i] <= 'm')
        {
            c = str[i] + (25 - ((str[i] - 'a') * 2));
            write(1, &c, 1);
        }
        else if(str[i] >= 'N' && str[i] <= 'Z')
        {
            c = str[i] - (25 + ((str[i] - 'Z') * 2));
            write(1, &c, 1);
        }
        else if(str[i] >= 'n' && str[i] <= 'z')
        {
            c = str[i] - (25 + ((str[i] - 'z') * 2));
            write(1, &c, 1);
        }
        else
            write(1, &str[i], 1);
        i++;
    }
}

int    main(int argc, char **argv)
{
    if(argc == 2)
        alpha_mirror(argv[1]);
    else
        write(1, "\n", 1);
    return (0);
}