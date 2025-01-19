#include <stdlib.h>
#include <stdio.h>
#include "flood_fill.h"

char** make_area(char** zone, t_point size)// Esta función se encarga de crear una nueva zona (un arreglo de punteros a cadenas) de tamaño dinámico, de acuerdo con las dimensiones dadas por size.
//Recibe zone que es un arreglo de punteros que apunta a cadenas de caracteres.
//y size, que es una estructura que contiene los valores x (8) e y (5), que representa las dimensiones del mapa.
{
	char** new;//Es un puntero a un puntero. Esto significa que char** es una variable que almacena la dirección de otro puntero a una cadena de caracteres.
	//¿por qué haríamos esto? Bueno, en este caso, estamos manejando un arreglo bidimensional de caracteres. Es decir, necesitamos un arreglo de varias cadenas de caracteres, no solo una. Y para poder manejar eso, necesitamos usar punteros a punteros.
	new = malloc(sizeof(char*) * size.y);//La multiplicación sizeof(char*) * size.y significa que estamos reservando memoria para size.y punteros a char. En otras palabras, estamos reservando un espacio para 5 punteros a cadenas.
	//la memoria que reservamos con malloc se obtiene en el montón (heap), lo que significa que no se reserva en la pila (stack), y podemos acceder a ella durante todo el tiempo que queramos hasta que la liberemos
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);//new[i]: Esto se refiere al puntero que apunta a la fila i-ésima del nuevo mapa.
									//malloc(size.x + 1): Aquí se está reservando memoria para una cadena de caracteres que tenga size.x caracteres más 1 extra para el carácter nulo (\0) que marca el final de la cadena.
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];//Este bucle interno recorre cada carácter de la fila y lo copia desde la fila correspondiente de zone al nuevo mapa new:
			//new[i][j] = zone[i][j]: Copia el carácter de la fila i de zone al nuevo mapa new.
		new[i][size.x] = '\0';//Se añade el caracter nulo al final de la fila.
	}

	return new;
	//Al devolver new, el puntero se pasa de vuelta al lugar donde fue llamada la función, en este caso, en main.
	//Así que en main, area ahora apunta a la misma memoria que new. Es decir, area tiene acceso a las mismas cadenas que se crearon y copiaron en la función make_area.
}

int main(void)
{
	t_point size = {8, 5};//t_point size = {8, 5};, se crea una estructura en memoria que contiene los dos datos (8 y 5), almacenados en dos campos consecutivos llamados x e y. Representa un punto en 2D con dos coordenadas (x y y).
	/* tambien se puede declarar asi size:
	t_point size;
	size.x = 8;
	size.y = 5;
	*/
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};//Declara un array de cadenas (un array de punteros a char) que apuntan a 5 cadenas de caracteres (strings). Cada elemento de este array es un puntero que apunta a una cadena de caracteres. Define la "zona" inicial como un mapa 2D representado por cadenas de caracteres: Cada cadena es una fila de la matriz. 1 representa áreas sólidas, y 0 representa áreas vacías. zone[i] es un puntero a la cadena i-ésima (es decir, una fila de tu mapa 2D). zone[i][j] es el carácter que se encuentra en la posición j-ésima de la cadena i.

	char**  area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");

	t_point begin = {7, 4};//La línea t_point begin = {7, 4}; crea una variable llamada begin de tipo t_point, que es una estructura, y la inicializa con los valores x = 7 e y = 4.
	//begin indica un lugar específico en el mapa donde realizar una operación, como por ejemplo una inicialización de algún algoritmo (por ejemplo, el algoritmo de "flood fill").
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
}