#include "flood_fill.h"
#include <stdio.h>
#include <stdlib.h>

void fill(char **tab, t_point size, t_point cur, char to_fill)
{
    if(cur.x < 0 || cur.x >= size.x || cur.y < 0 || cur.y >= size.y || tab[cur.y][cur.x] != to_fill)
        return;
    tab[cur.y][cur.x] = 'F';
    fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
    fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
    fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
    fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

void flood_fill(char **tab, t_point size, t_point begin)
{
    fill(tab, size, begin, tab[begin.y][begin.x]);
}

char **make_area(char **zone, t_point size)
{
    char **new = malloc(size.y * sizeof(char*));
    for(int i = 0; i < size.y; i++)
    {
        new[i] = malloc(size.x + 1);
        for(int j = 0; j < size.x; j++)
            new[i][j] = zone[i][j];
        new[i][size.x] = '\0';
    }
    return new;
}

int main(void)
{
    t_point size = {8, 5};
    char *zone [] = {
        "11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};

    char **area = make_area(zone, size);
    for(int i = 0; i < size.y; i++)
        printf("%s\n", area[i]);
    printf("\n");

    t_point begin = {7, 4};
    flood_fill(area, size, begin);
    
    for(int i = 0; i < size.y; i++)
        printf("%s\n", area[i]);
    printf("\n");

    for(int i = 0; i < size.y; i++)
        printf("%s\n", zone[i]);

    return 0;
}

/*
en lugar de reservar memoria con malloc creando un arreglo de punteros a arrays de tamaño size.x llamado area, podría haber directamente trabajado con el arreglo de punteros zone?
ChatGPT said:
ChatGPT
Sí, podrías haber trabajado directamente con el arreglo de punteros zone sin necesidad de usar malloc. Si zone ya está definido como un arreglo de punteros a cadenas de longitud size.x, puedes pasarlo directamente a las funciones sin necesidad de reservar memoria adicional.
You said:
por que se reserva entonces memoria con malloc? que pasa con la memoria que hemos usado para crear el mapa inicial con char *zone []?
ChatGPT said:
ChatGPT
La razón para usar malloc es que zone es un arreglo de punteros a cadenas de caracteres (es decir, cada fila es una cadena estática). Cuando usas malloc, estás creando un nuevo arreglo dinámico (new) para almacenar el mapa, lo que permite modificarlo sin afectar el original (zone).
La memoria de zone es estática, lo que significa que no puedes modificar su tamaño o cambiar su contenido dinámicamente sin sobrescribir o corromper la memoria. Al usar malloc para new, creas una copia del mapa que puedes modificar sin afectar la memoria original de zone.
You said:
no podría entonces usar zone y cambiar los '1' por 'F'?
ChatGPT said:
ChatGPT
No podrías cambiar los '1' por 'F' directamente en zone porque zone es un arreglo de punteros a cadenas de caracteres constantes (no dinámicas). Las cadenas literales, como las que usas en zone[], están almacenadas en una sección de memoria de solo lectura, lo que significa que no puedes modificar su contenido directamente.
Usar malloc y crear una copia dinámica con new te da un espacio de memoria donde sí puedes hacer cambios sin restricciones.
You said:
es decir, que con malloc puedo modificar el contenido de las cadenas, asi como crear o eliminar nuevas filas o columnas
ChatGPT said:
ChatGPT
Exactamente. Con malloc puedes:
Modificar el contenido de las cadenas: A diferencia de las cadenas literales (como las de zone[]), las cadenas dinámicas creadas con malloc se almacenan en memoria dinámica, lo que permite que puedas cambiar su contenido (como reemplazar '1' por 'F').
Crear nuevas filas o columnas: Con malloc, puedes asignar memoria para nuevas filas y columnas según sea necesario, redimensionando dinámicamente el espacio del mapa. Esto no es posible con las cadenas literales estáticas, donde el tamaño y contenido son fijos.
*/