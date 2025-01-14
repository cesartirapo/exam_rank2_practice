#include <unistd.h>

void epur_str(char *str)
{
    int i = 0;
    int flg = 0;
    while(str[i] == ' ' || str[i] == '\t')//saltar los espacios o tabulaciones iniciales
        i++;
    while(str[i])
    {
        if(str[i] == ' ' || str[i] == '\t')//si me encuentro espacio en medio del string (no los espacios iniciales), activo flag para escribir luego un espacio. No solo eso, también elimina espacios intermedios.
            flg = 1;
        else//despues de haber activado flag e ignorar espacios intermedios, nos encontramos un caracter
        {
            if(flg)//antes de escribir la primera palabra, flag seguirá siendo 0
            {
                write(1, "   ", 3);
                flg = 0;
            }
            write(1, &str[i], 1);
        }
        i++;
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