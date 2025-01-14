#include <unistd.h>
#include <stdlib.h>   // Para malloc y free
#include <string.h>   // Para strlen

char    *ft_strcpy(char *s1, const char *s2)
{
    int i;
    i = 0;
    while(s2[i])
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
    return (s1);
}

int main()
{
    const char *s2 = "Hola"; // source
    char *s1 = malloc(strlen(s2) + 1);  // Reservamos espacio para destination
    ft_strcpy(s1, s2);
    free(s1);  // Liberar memoria después de usarla
    return (0);
}