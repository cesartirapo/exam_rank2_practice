#include <unistd.h>

void epur_str(char *str)
{
    int i = 0;
    int flg = 0;

    // Saltar espacios iniciales
    while (str[i] == ' ' || str[i] == '\t')
        i += 1;

    // Procesar la cadena
    while (str[i])
    {
        if (str[i] == ' ' || str[i] == '\t')
            flg = 1;
        else
        {
            if (flg)
                write(1, " ", 1);
            flg = 0;
            write(1, &str[i], 1);
        }
        i += 1;
    }
    write(1, "\n", 1);
}

int main(int argc, char **argv)
{
    if (argc == 2)
        epur_str(argv[1]);
    else
        write(1, "\n", 1);
    return (0);
}