
#include <stdio.h>
#include <stdlib.h>

// Declaración de la función para ordenar
void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i = 0;
	int	temp;

	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i+ 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}

int main(int argc, char **argv)
{
    if (argc < 2) // Verificar si se proporcionaron números
    {
        printf("Usage: %s num1 num2 ...\n", argv[0]);
        return 1; // Salimos con error si no hay números
    }

    // Número de elementos que se pasaron
    unsigned int size = argc - 1;

    // Crear un array para almacenar los números
    int tab[size];

    // Convertir los argumentos (que son cadenas) en enteros
    for (unsigned int i = 0; i < size; i++)
    {
        tab[i] = atoi(argv[i + 1]); // `atoi` convierte cada cadena a un entero
    }

    // Mostrar los números antes de ordenar
    printf("Before sorting:");
    for (unsigned int i = 0; i < size; i++)
    {
        printf(" %d", tab[i]);
    }
    printf("\n");

    // Llamar a la función para ordenar
    sort_int_tab(tab, size);

    // Mostrar los números después de ordenar
    printf("After sorting:");
    for (unsigned int i = 0; i < size; i++)
    {
        printf(" %d", tab[i]);
    }
    printf("\n");

    return 0; // Salimos sin errores
}