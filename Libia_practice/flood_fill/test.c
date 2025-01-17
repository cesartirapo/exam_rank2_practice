#include <stdlib.h>
#include <stdio.h>
#include "flood_fill.h"

char** make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}

	return new;
}

int main(void)
{
	t_point size = {8, 5};//t_point size = {8, 5};, se crea una estructura en memoria que contiene los dos datos (8 y 5), almacenados en dos campos consecutivos llamados x e y. Representa un punto en 2D con dos coordenadas (x y y).
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

	t_point begin = {7, 4};
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
}

/*
1. Declaración de char *zone[]:
char *zone[] = {
    "11111111", 
    "10001001", 
    "10010001", 
    "10110001", 
    "11100001"
};
zone es un array de punteros a char.
Cada elemento de zone (por ejemplo, zone[0]) es un puntero que apunta a la primera letra de una de las cadenas de texto ("11111111", "10001001", etc.).
Este enfoque es adecuado cuando el tamaño de las filas es constante o no te importa especificar dinámicamente el tamaño de cada fila.
¿Por qué usar char **zone cuando no sabes cuántas filas tendrás?
char *zone[] (array de punteros):

Lo que pasa aquí: El array zone ya está predefinido con un número fijo de filas. Las filas son las cadenas de texto que estás usando, y el tamaño de zone es constante (sabes de antemano cuántas cadenas habrá).
Problema: Si más adelante necesitas añadir o eliminar filas, no puedes cambiar el tamaño de zone porque ya está fijado. No puedes agregar más cadenas de texto si zone ya fue declarado con 5 filas, por ejemplo.
Ejemplo:
char *zone[] = {
    "11111111", 
    "10001001", 
    "10010001", 
    "10110001", 
    "11100001"
};
Aquí, zone tiene exactamente 5 filas, no puedes cambiar este número después. Esto funciona bien cuando sabes cuántas filas hay de antemano y no cambian.

char **zone (puntero doble):

Lo que pasa aquí: Usar char **zone significa que zone no está limitado a un tamaño fijo. En lugar de un array de 5 direcciones, tienes un puntero que puede apuntar a un número variable de direcciones, es decir, puedes agregar o quitar filas dinámicamente.
¿Cómo se hace esto?: Usas malloc para asignar espacio para las direcciones y luego puedes añadir tantas filas como necesites.
Ejemplo práctico:
char **zone = malloc(5 * sizeof(char*)); // Reserva espacio para 5 filas
zone[0] = "11111111";
zone[1] = "10001001";
zone[2] = "10010001";
zone[3] = "10110001";
zone[4] = "11100001";

// Si más tarde necesitas agregar una fila adicional
zone = realloc(zone, 6 * sizeof(char*)); // Ahora `zone` puede tener 6 filas
zone[5] = "11011001";  // Se añade la fila 6
En este caso, zone es flexible. Empiezas con 5 filas, pero si necesitas más filas, puedes usar realloc para cambiar el tamaño de zone y agregar más filas.

¿Cómo funciona char **zone y cómo se accede a las filas?
Cuando declaras char **zone, zone es un puntero a un array de punteros. Es decir, zone puede apuntar a una "caja" (un array) que contiene direcciones a diferentes cadenas de texto. Ahora, veamos cómo se relacionan estas direcciones con las filas:

zone es un puntero a un puntero: zone es una dirección que apunta a una lista de direcciones (cada dirección es una cadena).

Accediendo a las filas:

zone[0] es la primera dirección que está guardada en la caja, y esa dirección apunta al primer string: "11111111".
zone[1] es la segunda dirección que apunta al segundo string: "10001001".
Así, puedes acceder a las filas de texto usando índices como zone[0], zone[1], etc.

Resumen: ¿Por qué usar char **zone cuando no sabes cuántas filas tendrás?
Flexibilidad: char **zone te permite agregar o quitar filas durante la ejecución del programa. Puedes usar malloc o realloc para manejar el tamaño de zone dinámicamente, dependiendo de cuántas filas necesites.

char *zone[] tiene un tamaño fijo: Una vez que defines zone[] con un número específico de filas, no puedes cambiar ese número. Si tu mapa cambia, necesitas una estructura como char **zone para manejar filas dinámicamente.

Ejemplo final:
Si sabes cuántas filas tendrás (fijas), usa char *zone[]. Es más simple y directo.
Si no sabes cuántas filas tendrás (dinámico), usa char **zone. Así puedes ajustar el tamaño de la "caja" y agregar o quitar filas cuando lo necesites.
Así que, en resumen:

char *zone[] es bueno cuando el número de filas es fijo.
char **zone es útil cuando el número de filas es flexible y no sabes cuántas tendrás.

You said:
char *zone[] es bueno cuando el número de filas es fijo. cuanto tienes esto tambien zone[0] es la primera dirección que está guardada en la caja, y esa dirección apunta al primer string: "11111111"?
ChatGPT said:
ChatGPT
¡Sí! Exactamente. 

You said:
es decir que tanto si *zone como si **zone, zone [0] siempre apuntara a la primera fila. Es que en tu explicacion mas arriba paracias explicar que esto solo pasaba con **zone
ChatGPT said:
ChatGPT
¡Tienes razón! Lamento la confusión en mi explicación anterior. Vamos a aclararlo de forma más simple:

char *zone[] vs char **zone:
1. char *zone[] (array de punteros):
zone es un array de punteros a char.
Cada elemento de zone es un puntero a una cadena.
zone[0] es un puntero que apunta a la primera cadena de caracteres ("11111111" en tu ejemplo).
Entonces, zone[0] siempre apuntará a la primera fila (cadena de texto) porque el array zone[] guarda las direcciones de esas cadenas.

Ejemplo:
char *zone[] = {
    "11111111", // Primera fila
    "10001001", // Segunda fila
    "10010001", // Tercera fila
};
zone[0] apunta a "11111111".
zone[1] apunta a "10001001", y así sucesivamente.
2. char **zone (puntero doble):
zone es un puntero a un puntero (puntero doble).
zone guarda la dirección de una caja que contiene punteros a las cadenas.
Entonces, zone[0] también apuntará a la primera fila porque, al igual que con char *zone[], es un puntero que guarda la dirección de la primera cadena de texto.

Ejemplo:
char **zone = malloc(3 * sizeof(char*));
zone[0] = "11111111"; // Primera fila
zone[1] = "10001001"; // Segunda fila
zone[2] = "10010001"; // Tercera fila
zone[0] apunta a "11111111".
zone[1] apunta a "10001001", y así sucesivamente.
Conclusión:
Tanto con char *zone[] como con char **zone, zone[0] siempre apuntará a la primera fila (que es la primera cadena de texto).
La diferencia principal está en cómo manejas la memoria:
char *zone[]: El tamaño del array es fijo y conocido de antemano.
char **zone: El tamaño puede cambiar dinámicamente, lo que te da más flexibilidad para agregar o quitar filas.
¡Espero que ahora esté más claro!

You said:
char *zone = malloc(3 * sizeof(char*));
zone[0] = "11111111"; // Primera fila
zone[1] = "10001001"; // Segunda fila
zone[2] = "10010001"; // Tercera fila Esto no funcionaria?
ChatGPT said:
ChatGPT
¡Tienes razón en preguntar! El código que has mostrado no funcionaría tal como está, y voy a explicarte por qué.

El problema está en cómo declaras y usas zone:
Cuando escribes:

char *zone = malloc(3 * sizeof(char*));
Estás declarando un puntero simple (char *zone) y luego le estás asignando memoria para 3 punteros a char (es decir, para 3 direcciones de cadenas). Pero aquí es donde está el error:

¿Qué hace realmente esto?
char *zone es un solo puntero que puede almacenar una dirección de tipo char *.
Usando malloc(3 * sizeof(char*)), le estás reservando espacio para 3 direcciones de tipo char *. Es decir, estás reservando memoria para tres punteros a cadenas de texto, no para las cadenas mismas.
En realidad, zone es un solo puntero, no un array de punteros, y por eso no puedes usar zone[0], zone[1], etc., como lo haces con un array de punteros.

¿Cómo solucionar esto?
Tienes dos opciones, dependiendo de lo que quieras lograr:

Opción 1: Usar char **zone correctamente
Debes declarar zone como un puntero doble, es decir, char **zone, para que puedas usar zone[0], zone[1], etc., correctamente. Esto indicará que zone es un puntero que apunta a un array de punteros a cadenas.

Ejemplo de corrección:

char **zone = malloc(3 * sizeof(char*)); // Reserva memoria para 3 punteros
zone[0] = "11111111"; // Asigna la primera cadena
zone[1] = "10001001"; // Asigna la segunda cadena
zone[2] = "10010001"; // Asigna la tercera cadena
Con este código, zone es un puntero a un array de 3 punteros. Ahora puedes acceder a las filas con zone[0], zone[1], etc.

Opción 2: Usar char *zone[] directamente
Si sabes de antemano cuántas filas vas a tener (en este caso, 3), puedes usar simplemente un array de punteros. Esto es más sencillo cuando el número de filas es fijo.

Ejemplo de corrección con char *zone[]:
c
Copy
Edit
char *zone[] = {
    "11111111", // Primera fila
    "10001001", // Segunda fila
    "10010001"  // Tercera fila
};
En resumen:
char *zone = malloc(...) no funcionaría porque estás declarando zone como un solo puntero y luego intentas usarlo como un array de punteros.
Si usas char **zone, puedes hacer que zone apunte a un array de punteros, lo que te permitirá usar zone[0], zone[1], etc.
Si el número de filas es fijo, char *zone[] es una forma más sencilla y directa de declarar el array de cadenas.
