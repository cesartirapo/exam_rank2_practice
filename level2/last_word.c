#include <unistd.h>
void    last_word(char *str)
{
    int    i;
    i = 0;
    while(str[i])
        i++;
    while(i > 0 && (str[i] == 0 || str[i] == 9 || str[i] == 32))
        i--;
    while(i > 0 && (str[i] >= 33 && str[i] <= 126))
        i--;
    i++;
    while(str[i] && str[i] >= 33 && str[i] <= 126)
    {
        write(1, &str[i], 1);
        i++;
    }
    write(1, "\n", 1);
}

int    main(int argc, char **argv)
{
    if(argc == 2)
        last_word(argv[1]);
    else
        write(1, "\n", 1);
    return (0);
}