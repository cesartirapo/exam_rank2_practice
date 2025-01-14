
#include <stdio.h>

char    *ft_strdup(char *src)
{
    int i;
    i = 0;
    while(src[i])
        i++;
    char    *copy = malloc ((i + 1) * sizeof(char));//Hemos creado un puntero porque malloc devuelve la dirección de la memoria reservada, y necesitamos almacenar esa dirección para poder acceder a la memoria y manipularla.
    if(copy == NULL)
        return NULL;
    i = 0;
    while(src[i])
    {
        copy[i] = src[i];
            i++;
    }
    copy[i] = '\0';
    return (copy);
}