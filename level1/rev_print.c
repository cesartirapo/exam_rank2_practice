#include <unistd.h>

void    rev_print (char *str)
{
    int len;
    len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    while (len > 0)
    {
        write(1, &str[len - 1], 1);
        len--;
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
        write(1, "\n", 1);
    else
    {
        rev_print(argv[1]);
        write(1, "\n", 1);
    }
    return (0);
}