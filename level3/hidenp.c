#include <unistd.h>

void    hidenp(char *s1, char *s2)
{
    int i;
    int j;
    i = 0;
    j = 0;
    // Si s1 está vacío, siempre está "oculto" en s2
    if (s1[0] == '\0')
    {
        write(1, "1\n", 2);
        return;
    }
    while(s2[i])
    {
        if(s2[i] == s1[j])
            j++;
        if(s1[j] == '\0')
          {
            write(1, "1\n", 2);
            return;
          }
        i++;
    }
    write(1, "0\n", 2);
}

int main(int argc, char **argv)
{
    if(argc == 3)
        hidenp(argv[1], argv[2]);
    else
        write(1, "\n", 1);
    return (0);
}