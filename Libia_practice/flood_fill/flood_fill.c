#include "flood_fill.h"

void	fill(char **tab, t_point size, t_point cur, char to_fill)
//el argumento cur en la función fill recibe el valor del punto begin que le pasa la función flood_fill. Representa la posición actual que está siendo procesada en cada llamada recursiva de fill.
//Inicialmente, cur sí es igual al punto begin, porque es donde empieza el llenado. Pero en las llamadas recursivas, cur cambia a las posiciones vecinas (izquierda, derecha, arriba, abajo). Por lo tanto, cur evoluciona mientras el algoritmo explora el área.
//char to_fill: El carácter original que se debe reemplazar con 'F'. Esto asegura que solo se llenen las celdas con el mismo carácter que el punto inicial.
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x || tab[cur.y][cur.x] != to_fill)
		return;
//cur.y < 0: Verifica si la posición actual en la fila (cur.y) está fuera del límite superior del mapa (por encima de la primera fila). Si estamos en una fila negativa, significa que hemos salido del área válida, por lo que se detiene la recursión.
//cur.y >= size.y: Verifica si la posición actual en la fila (cur.y) está fuera del límite inferior del mapa (por debajo de la última fila). Si superamos el número total de filas, también estamos fuera del área válida.
//cur.x < 0: Verifica si la posición actual en la columna (cur.x) está fuera del límite izquierdo del mapa (antes de la primera columna). Esto asegura que no accedamos a una posición inválida hacia la izquierda.
//cur.x >= size.x: Verifica si la posición actual en la columna (cur.x) está fuera del límite derecho del mapa (más allá de la última columna). Esto evita acceder a posiciones fuera de los límites hacia la derecha.
//tab[cur.y][cur.x] != to_fill: Comprueba si el carácter en la posición actual no coincide con el carácter original que se está llenando, es decir to_fill, que en este caso es '1'. Si estamos en una celda que no es parte del área objetivo, no hay nada que llenar, así que detenemos la recursión.
//Este punto anterior es el mas interesante: 
//Cuando se ejecuta el return debido a que se encontró un '0' o un borde del mapa, la función regresa al punto anterior de la recursión, es decir, al último punto que llamó a la función fill.
//Por ejemplo: La recursión empieza en (7, 4) y llena celdas adyacentes con '1'.
//Si llega a una celda con '0', ejecuta return y regresa a la celda anterior en la pila de llamadas (es decir, vuelve al punto desde donde se llamó a la función).
//Desde ese punto anterior, la recursión seguirá buscando en las demás celdas adyacentes que no hayan sido procesadas aún.
//Por lo tanto, la recursión no se detiene globalmente; se sigue procesando en otras áreas del mapa que aún pueden contener '1'.
	tab[cur.y][cur.x] = 'F';// asigna el carácter 'F' a la celda en la posición (cur.y, cur.x) del mapa. Esto es lo que modifica el mapa durante el proceso de flood fill.
	//cuando escribimos 'F' en begin (7, 4), la siguiente linea llama a fill de forma recursiva enviando en su tercer argumento una estructura de tipo t_point con x = 6 e y = 4. Despues, tab[cur.y][cur.x] comprobará el caracter de la izquierda (4, 6) o para entedernos mejor (6, 4) (si usamos la sintaxis de (x, y) en el que hay un '0'.
	//Por tanto, se cumple la condicion if, se ejecuta return y la siguiente linea que se ejecuta es la que comprueba el caracter de la derecha (8, 4) que se sale del mapa.
	//El caracter de la derecha cumple con la condicion cur.x >= size.x dentro del if ya que cur.x es 8, y es igual que size.x.
	//Se ejecuta return, pasamos a la siguiente comprobación que es el caracter de arriba (7, 3), en el que hay un '1'.
	//Escribimos F y ejecutamos la siguiente línea del codigo por orden: fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill); que explorará la celda (6,3).
	//De este modo, las comprobaciones se hacen primero a la izquierda, luego derecha, luego arriba y luego abajo.
	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);//se está llamando a la función fill para explorar la celda a la izquierda de la celda actual, es decir, en la columna anterior (cur.x - 1) manteniendo la misma fila (cur.y).
	//(t_point){cur.x - 1, cur.y}: Es la nueva coordenada que se pasa, que representa la celda a la izquierda de la actual (restando 1 a la columna cur.x).
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	//(t_point){cur.x + 1, cur.y}: Es la nueva coordenada que se pasa, que representa la celda a la derecha de la actual (sumando 1 a la columna cur.x).
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
		//(t_point){cur.x, cur.y - 1}: Es la nueva coordenada que se pasa, que representa la celda encima de la actual (restando 1 a la fila cur.y).
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
	//(t_point){cur.x, cur.y + 1}: Es la nueva coordenada que se pasa, que representa la celda debajo de la actual (sumando 1 a la fila cur.y).

}

//En lugar de tener una función intermedia (flood_fill), podrías llamar a fill directamente desde main, pasando los mismos parámetros, y de hecho eso simplificaría el código. 
//Si intentas llamar directamente a fill desde main, necesitarías algo como esto: fill(area, size, begin, area[begin.y][begin.x]);
//La función flood_fill en tu código actual está sirviendo como un envoltorio para llamar a la función fill con los parámetros correctos, lo cual no es estrictamente necesario si ya tienes esos parámetros disponibles en main.
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