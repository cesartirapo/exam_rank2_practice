#include "flood_fill.h"

void	fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x || tab[cur.y][cur.x] != to_fill)
		return;
	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

void	flood_fill(char **tab, t_point size, t_point begin)
//area: Es un arreglo de punteros que apunta a las filas del mapa que creamos antes con make_area. Cada elemento de area es una cadena que representa una fila del mapa.
//size: Es una estructura t_point que contiene las dimensiones del mapa: size.x = 8 (el número de columnas) y size.y = 5 (el número de filas).
//begin: Es otra estructura t_point que contiene las coordenadas de inicio para la operación de flood fill: begin.x = 7 y begin.y = 4, que se refiere a la posición (7, 4) en el mapa.
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}
//tab: Es area, que es un puntero a un arreglo de cadenas. Cada fila del mapa se encuentra en tab[i].
//size: Es la estructura size (8, 5) que contiene las dimensiones del mapa (el número de filas y columnas).
//begin: Es la estructura begin (7, 4) que contiene las coordenadas de inicio (el punto donde empezar el flood fill).
//tab[begin.y][begin.x]: Este es el carácter en la posición de inicio (begin.y fila y begin.x columna) en area. Este valor será utilizado para identificar qué tipo de "zona" se va a llenar durante el flood fill (normalmente se usa el valor del carácter de esa posición para determinar qué área llenar).