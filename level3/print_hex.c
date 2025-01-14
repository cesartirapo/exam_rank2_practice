
#include <stdlib.h>
#include <unistd.h>

void    print_hex(int n)
{
    if(n >= 16)
        print_hex(n / 16);
    write(1, &"0123456789abcdef"[n % 16], 1);
}

int main(int ac, char **av)
{
    if (ac == 2)
        {
            int n = atoi(av[1]);
            if(n < 0)
            {
                write(1, "\n", 1);
                return (0);
            }
            else
                print_hex(n);
            write(1, "\n", 1);
        }
    else
        write(1, "\n", 1);
    return (0);
}