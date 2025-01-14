#include <unistd.h>
void    rot_13(char *str)
{
    int    i;
    char   new_char;
    i = 0;
    while(str[i])
    {
        if((str[i] >= 'a' && str[i] <= 'm') || (str[i] >= 'A' && str[i] <= 'M'))
        {
            new_char = str[i] + 13;
            write(1, &new_char, 1);
        }
        else if((str[i] >= 'm' && str[i] <= 'z') || (str[i] >= 'M' && str[i] <= 'Z'))
        {
            new_char = str[i] - 13;
            write(1, &new_char, 1);
        }
        else
            write(1, &str[i], 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc > 1)
        rot_13(argv[1]);
    return (0);
}