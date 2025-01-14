#include <unistd.h>

void    putnbr(int n)
{
    if(n > 9)
    {
        putnbr(n / 10);
    }
    write(1, &"0123456789"[n % 10], 1);//Esta línea es válida porque &"0123456789"[n % 10] genera un puntero al carácter correspondiente en el literal de cadena "0123456789". 
    //write(1, (n % 10) + '0', 1); Esta línea no es válida porque el segundo argumento de write debe ser un puntero (const void *), pero (n % 10) + '0' es un valor entero (char) que representa el carácter correspondiente al dígito n % 10. 
}

void    add_prime_sum(int n)
{
    int i;
    int result;
    int primo;
    result = 0;
     while(n >= 2)
     {
        primo = 1;
        if(n == 2 || n == 3)
        {
            result += n;
            n--;
            continue;
        }
        if(n % 2 == 0)
        {
            n--;
            continue;
        }
        i = 2;
        while(i * i <= n)
        {
            if(n % i == 0)
            {
                primo = 0;
                break;
            }
            i++;
        }
        if(primo == 1)
        {
            result += n;
        }
        n--;
     }
     putnbr(result);
}

void    my_atoi(char *str)
{
    int n;
    int i;
    n = 0;
    i = 0;
    while(str[i])
    {
        if(str[i] == '-')
        {
            write(1, "\n", 1);
            return;
        }
        n = (str[i] - '0') + (n * 10);
        i++;
    }
    add_prime_sum(n);
}

int    main(int argc, char **argv)
{
    if(argc == 2)
        my_atoi(argv[1]);
    else
        write(1, "\n", 1);
    return (0);
}