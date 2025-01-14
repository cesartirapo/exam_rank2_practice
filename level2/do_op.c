#include <unistd.h>

void    putnmb(int  n)
{
    char    c;
    if(n == -2147483648)
    {
        write(1, "-2147483648", 10);
        return ;
    }
    if(n < 0)
    {
        write(1, "-", 1);
        n = -n;
    }
    if(n > 9)
    {
        putnmb(n / 10);
    }
    c = (n % 10) + '0';
    //write(1, &"0123456789"[n % 10], 1);
    write(1, &c, 1);
}

int    atoi(char *str)
{
    int    i;
    int    result;
    char   sign;
    i = 0;
    result = 0;
    sign = 1;
    while(str[i])
    {
        if(str[i] == '-')
            sign *= -1;
        else if (str[i] == '+')
            i++;
        else if(str[i] >= '0' && str[i] <= '9')
            result = result * 10 + str[i] - '0';
        i++;
    }
    return (result * sign) ;
}

void    do_op(char *a, char *oper, char *b)
{
    int    result;
    if (oper[0] == '+')
        result = atoi(a) + atoi (b);
    if (oper[0] == '-')
        result = atoi(a) - atoi (b);
    if (oper[0] == '*')
        result = atoi(a) * atoi (b);
    if (oper[0] == '/')
        result = atoi(a) / atoi (b);
    if (oper[0] == '%')
        result = atoi(a) % atoi (b);
    putnmb(result);
    write(1, "\n", 1);
}

int    main(int argc, char **argv)
{
    if(argc == 4)
    {
        do_op(argv[1], argv[2], argv[3]);
        write(1, "\n", 1);
    }
    else
        write(1, "\n", 1);
    return (0);
}