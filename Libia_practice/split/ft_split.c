#include <stdio.h>
#include <stdlib.h>

char **ft_split(char const *s, char c)
{
    if (!s) return NULL;//Si el string esta vacio devolvemos nul
    int word_count = 0;
    int i = 0;
    while (s[i])//continua hasta que lleguemos al final del string
    {
        while (s[i] == c)
            i++;
        if (s[i] != '\0')
        {
            word_count++;
            while (s[i] && s[i] != c)
                i++;
        }
    }
    char **array = (char **)malloc((word_count + 1) * sizeof(char *));
    if (!array) return NULL;
    int index = 0;
    i = 0;
    while (s[i])
    {
        while (s[i] == c)//pasamos los espacios
            i++;
        if (s[i] != '\0')//si el siguiente caracter no es el nulo
        {
            int start = i;//inicializamos el cursor start en la posicion de i
            while (s[i] && s[i] != c)//corremos i hasta el final del string o hasta encontrarnos con un espacio.
                i++;
            int length = i - start;//la longitud de la nueva palabra es la posicion de i menos start
            array[index] = (char *)malloc((length + 1) * sizeof(char));//reservamos memoria para la palabra con length mas 1 para el caracter nulo.
            if (!array[index])//en caso de no haber conseguido reservar memoria, liberamos tanto el puntero que apunta a la palabra como el array de punteros.
            {
                int j = 0;
                while (j < index)//¿Que pasaria si index es 0? podriamos liberar array[0]? No haría falta, ya que si index = 0 esto significa que no hemos asignado memoria para ninguna palabra, incluido array [0].
                                //Este bucle es relevante en el caso de que ya se haya asignado memoria para alguna palabra (es decir, index > 0), el bucle se ejecutará y liberará todos los punteros desde array[0] hasta array[index - 1](incluido), limpiando correctamente la memoria asignada antes del error.
                {
                    free(array[j]);
                    j++;
                }
                free(array);
                return NULL;
            }
            int j = 0;
            while (j < length)//Si no ha habido ningun problema en la reserva de memoria y mientras que j sea menor que la longitud de la palabra
            {
                array[index][j] = s[start + j];//copiamos en el espacio de memoria reservado los caracteres del string s desde start hasta el final de la palabra
                j++;
            }
            array[index][length] = '\0';//finalmente añadimos el caracter nulo en el espacio de memoria reservado para la palabra
            index++;
        }
    }
    array[index] = NULL;//Por que hacemos esto? Muy buena pregunta. Resulta que hemos guardado memoria para tantos punteros como palabras mas 1. Este mas uno es para crear un ultimo puntero que apuntara a NULL.
                        //Esto se hace porque puede ser muy util si quisieramos iterar sobre el array y poder indicar su final. Por ejemplo en la funcion main, cuando hemos usado printf para imprimir las palabras hasta llegar a ese puntero que apunta a NULL "while(array[i])"
    return array;
}

int main(int ac, char **av)
{
    char **array = ft_split(av[1], ' ');//creamos un array de punteros y llamamos a ft_split con el string y el caracter 'espacio'
    int i = 0;
    while(array[i])
    {
        printf("%s\n", array[i]);//imprimimos la palabra a la que apunta el puntero 2 del array de punteros.
        i++;
    }
    return 0;
}