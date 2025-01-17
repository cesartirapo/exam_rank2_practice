#include <stdio.h>
#include <stdlib.h>  // Para usar malloc
#include "ft_list.h" //Cuando usas #include en un archivo .c, el compilador copia y pega el contenido del archivo .h en ese lugar. En un proyecto grande, puedes incluir el mismo archivo .h en varios lugares. 
int ft_list_size(t_list *begin_list)
{
    int i = 0;  // Inicializa un contador en 0
    
    // Recorre la lista mientras el nodo actual no sea NULL
    while (begin_list != NULL)  // Mientras haya nodos en la lista
    {
        i++;  // Incrementa el contador de nodos. El incremento se coloca antes porque i = 0, al acceder al bucle sabemos ya que al menos hay un nodo al que esta apuntando begin_list. Por tanto, tiene sentido incrementarlo ya una unidad.
        begin_list = begin_list->next;  // Avanza al siguiente nodo. Accede al campo next del nodo al que apunta begin_list, es decir, esta accediendo al campo next del primer nodo, que esta apuntado al segundo nodo. Por tanto, ahora begin_list apunta al segundo nodo. Como apunta al segundo, el bucle se ejecutara una vez mas incrementandose i, que ahora vale 2. De nuevo accedemos al campo next del nodo 2 que apunta al nodo 3 y asignamos esta direccion de memoria a begin_list, que ahora apunta al nodo 3. El bucle se ejecuta una vez mas incrementandose i, que ahora vale 3. En la siguiente asignacion ahora begin_list apunta a la direccion donde apunta el campo next del nodo 3, que resulta ser nulo. El bucle se detiene con i = 3.
    }
    
    // Devuelve el contador de nodos
    return i;  // El número total de nodos
}

// Función para crear un nuevo nodo. Devuelve un puntero que apunta a la direccion de memoria del nodo recien creado
t_list *create_node(void *data)//La función recibe (void *data) para que pueda aceptar cualquier tipo de dato. El tipo void * es un puntero genérico, lo que significa que puede apuntar a valores de cualquier tipo (int, char, structs, etc.). Esto hace que la lista sea flexible y pueda almacenar datos de cualquier tipo, según lo que necesites.
{
    t_list *new_node = (t_list *)malloc(sizeof(t_list));  // Reservamos memoria para un nuevo nodo
    //sizeof(t_list): Calcula cuánta memoria necesitamos para almacenar un nodo de tipo t_list. Un nodo tiene dos partes (un puntero y otro puntero), así que la cantidad de memoria que se reserva depende de cómo definimos t_list.
    //aqui por cierto ha habido un casting con (t_list *). malloc devuelve un puntero de tipo void *, pero nosotros sabemos que estamos creando un nodo, así que convertimos ese puntero en un puntero a t_list.

    new_node->data = data;
//new_node: Es el nombre de nuestra variable que va a almacenar la dirección de memoria del nuevo nodo. new_node->data: El operador -> se usa para acceder a un miembro de una estructura a través de un puntero. Es como si abriéramos el nodo (new_node) y tomáramos el lugar donde está guardado el dato (data). data: Es el dato que pasamos cuando llamamos a create_node. Por ejemplo, si pasamos la cadena "Primer nodo", esta línea asigna ese valor al campo data del nodo. Por tanto, el puntero data (que apunta a "Primer nodo") se asigna al campo data del nodo (new_node). De esta forma, el nodo ahora contiene la dirección de memoria del string "Primer nodo". Así que new_node->data apunta al mismo lugar en memoria que data.

    new_node->next = NULL;   // Inicializamos el puntero 'next' como NULL. Todos los nodos creados tienen su campo next inicializado en NULL, de manera que no apuntan a nada al princpio.
    return new_node;  // Devolvemos el puntero al nuevo nodo
}

int main() {
    // Creamos algunos nodos
    t_list *node1 = create_node("Primer nodo");//t_list es el tipo de la variable, al igual que int o char.
    //En este caso, t_list es un tipo de dato personalizado que hemos definido usando la estructura struct.
    //Aquí estamos llamando a la función create_node para crear un nodo que guarda el dato "Primer nodo". La dirección de este nodo se guarda en node1.
    //El asterisco en t_list *node1 indica que node1 es un puntero que apunta a una estructura t_list. Como create_node devuelve un puntero a un nodo, necesitamos declararlo como tal para almacenar esa dirección de memoria.
    //Al llamar a create_node("Primer nodo"), el literal "Primer nodo" (que es una dirección de memoria de tipo char *) se pasa como argumento. La función lo recibe a través de void *data, que puede almacenar la dirección de cualquier tipo de dato, incluido un char *.
    t_list *node2 = create_node("Segundo nodo");
    t_list *node3 = create_node("Tercer nodo");

    // Enlazamos los nodos
    node1->next = node2;  // El primer nodo apunta al segundo
    node2->next = node3;  // El segundo nodo apunta al tercero

    // El primer nodo es la cabeza de la lista
    t_list *begin_list = node1;
    //Al hacer begin_list = node1;, estamos diciendo que begin_list también va a apuntar al mismo nodo (el primer nodo de la lista). begin_list es un puntero de tipo t_list * que apunta a la estructura t_list que representa el primer nodo de la lista. Ambos punteros (begin_list y node1) apuntan a la misma dirección de memoria donde está almacenado ese primer nodo

    // Llamamos a la función ft_list_size para contar los nodos
    printf("El tamaño de la lista es: %d\n", ft_list_size(begin_list));//enviamos el puntero begin_list que apunta a la estructura que representa el primero nodo de la lista.
	printf("%s", (char *)node1->data);
    // Liberamos la memoria después de usarla (importante en C)
    free(node1);
    free(node2);
    free(node3);
    //free se usa para liberar la memoria que hemos reservado con malloc. Es importante liberar la memoria cuando ya no la necesitamos para evitar que se quede ocupada sin uso.


    return 0;
}

/*
1. Memoria reservada por malloc:

t_list *new_node = (t_list *)malloc(sizeof(t_list));
La función malloc reserva sólo la cantidad de memoria necesaria para almacenar la estructura t_list. Esta estructura tiene dos campos:

void *data: Este es un puntero, que ocupará 8 bytes en una arquitectura de 64 bits.
struct s_list *next: Este también es un puntero, que también ocupará 8 bytes en una arquitectura de 64 bits.
Por lo tanto, sizeof(t_list) es el tamaño de la estructura, que, en una arquitectura de 64 bits, sería:

8 bytes para el puntero data.
8 bytes para el puntero next.
Así que la memoria total reservada por malloc es 16 bytes (8 + 8 bytes).

2. ¿Se ha reservado memoria para la cadena?
No. La memoria para la cadena "Primer nodo" no se reserva dentro del malloc. Lo que malloc reserva es espacio para la estructura t_list (16 bytes), pero no para los datos a los que apunta el puntero data.

Cuando haces esta asignación:

new_node->data = data;
El valor de data (que en este caso es "Primer nodo") es una cadena literal, que ya tiene una ubicación en memoria en el programa. El puntero data del nodo simplemente apunta a esa ubicación de memoria.

Por lo tanto:

malloc reserva memoria para el nodo (16 bytes).
La cadena "Primer nodo" ya existe en otra parte de la memoria, no se reserva de nuevo con malloc. El puntero data simplemente apunta a esa cadena.
3. ¿malloc devuelve un puntero a la cadena?
No. malloc devuelve un puntero al nodo, no a la cadena. La cadena "Primer nodo" ya tiene su propia memoria asignada por el compilador, no es gestionada por malloc en este caso.

Entonces:

malloc devuelve un puntero a un bloque de memoria suficiente para almacenar la estructura t_list.
El puntero data en el nodo recién creado se asigna para que apunte a la memoria donde está almacenada la cadena "Primer nodo", pero esa memoria no la reserva malloc.
Resumen:
malloc reserva 16 bytes para la estructura t_list (8 bytes para el puntero data y 8 bytes para el puntero next).
No reserva memoria para la cadena "Primer nodo", ya que esa cadena es una constante que ya tiene su propia memoria.
El puntero data en el nodo apunta a la ubicación en memoria donde la cadena "Primer nodo" está almacenada.
*/
