#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int *ft_range(int start, int end)
{
    int i = 0;
    int len;

    // Calculamos la longitud del rango sin abs()
    if (start <= end)
        len = end - start + 1;  // Si el rango es ascendente
    else
        len = start - end + 1;  // Si el rango es descendente

    // Asignamos memoria para el rango
    int *range = (int *) malloc(len * sizeof(int));
    
    // Verificamos si malloc falló
    if (!range)
        return NULL;

    // Rellenamos el rango
    while (i < len)
    {
        // Llenamos el array con números en orden ascendente
        if (start < end)
            range[i] = end--;
        // Llenamos el array con números en orden descendente
        else
            range[i] = end++;
        i++;
    }
    
    // Devolvemos el rango
    return range;
}

int main()
{
    int start = 0;
    int end = -3;

    int *result = ft_range(start, end);
    
    // Verificamos si malloc falló
    if (result != NULL)
    {
        int len;

        // Calculamos la longitud del rango directamente
        if (start <= end)
            len = end - start + 1;  // Si el rango es ascendente
        else
            len = start - end + 1;  // Si el rango es descendente

        // Imprimimos los valores del rango
        for (int i = 0; i < len; i++)  
        {
            printf("%d ", result[i]);
        }
        printf("\n");

        free(result);  // Liberamos la memoria al final
    }
    else
    {
        printf("Error al asignar memoria.\n");
    }

    return 0;
}