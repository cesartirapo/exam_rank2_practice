#include <stdio.h>
#include <stdlib.h>  // Para usar malloc
#include "ft_list.h" //Cuando usas #include en un archivo .c, el compilador copia y pega el contenido del archivo .h en ese lugar.
//En un proyecto grande, puedes incluir el mismo archivo .h en varios lugares. 
int ft_list_size(t_list *begin_list)
{
    int i = 0;  // Inicializa un contador en 0
    
    // Recorre la lista mientras el nodo actual no sea NULL
    while (begin_list != NULL)  // Mientras haya nodos en la lista
    {
        i++;  // Incrementa el contador de nodos
        begin_list = begin_list->next;  // Avanza al siguiente nodo
    }
    
    // Devuelve el contador de nodos
    return i;  // El número total de nodos
}

// Función para crear un nuevo nodo
t_list *create_node(void *data) {
    t_list *new_node = (t_list *)malloc(sizeof(t_list));  // Reservamos memoria para un nuevo nodo
    new_node->data = data;  // Asignamos el dato al nodo
    new_node->next = NULL;   // Inicializamos el puntero 'next' como NULL
    return new_node;  // Devolvemos el puntero al nuevo nodo
}

int main() {
    // Creamos algunos nodos
    t_list *node1 = create_node("Primer nodo");
    t_list *node2 = create_node("Segundo nodo");
    t_list *node3 = create_node("Tercer nodo");

    // Enlazamos los nodos
    node1->next = node2;  // El primer nodo apunta al segundo
    node2->next = node3;  // El segundo nodo apunta al tercero

    // El primer nodo es la cabeza de la lista
    t_list *begin_list = node1;

    // Llamamos a la función ft_list_size para contar los nodos
    printf("El tamaño de la lista es: %d\n", ft_list_size(begin_list));

    // Liberamos la memoria después de usarla (importante en C)
    free(node1);
    free(node2);
    free(node3);

    return 0;
}

/*
t_list *create_node(void *data):

t_list: Es el tipo de dato de nuestro nodo. En otras palabras, indica que esta función va a crear un nodo de tipo t_list, que es una estructura que definimos en ft_list.h. Un nodo tiene dos cosas: un dato (data) y un puntero al siguiente nodo (next).
*: El asterisco significa que create_node devuelve un puntero, es decir, una dirección de memoria que apunta al nodo que creamos.
void *data: Esto significa que la función acepta un dato de cualquier tipo. void * es un tipo de puntero general, que puede apuntar a cualquier tipo de dato (por ejemplo, una cadena de texto, un número, etc.). El * significa que data es un puntero.
t_list *new_node = (t_list *)malloc(sizeof(t_list));:

malloc: Función que reserva una cantidad de memoria específica en el montón (es como un espacio en la memoria de la computadora que podemos usar para guardar datos).
sizeof(t_list): Calcula cuánta memoria necesitamos para almacenar un nodo de tipo t_list. Un nodo tiene dos partes (un puntero y otro puntero), así que la cantidad de memoria que se reserva depende de cómo definimos t_list.
(t_list *): malloc devuelve un puntero de tipo void *, pero nosotros sabemos que estamos creando un nodo, así que convertimos ese puntero en un puntero a t_list.
new_node: Es el nombre de nuestra variable que va a almacenar la dirección de memoria del nuevo nodo.
new_node->data = data;:

new_node->data: El operador -> se usa para acceder a un miembro de una estructura a través de un puntero. Es como si abriéramos el nodo (new_node) y tomáramos el lugar donde está guardado el dato (data).
data: Es el dato que pasamos cuando llamamos a create_node. Por ejemplo, si pasamos la cadena "Primer nodo", esta línea asigna ese valor al campo data del nodo.
new_node->next = NULL;:

next: Es el puntero que indica cuál es el siguiente nodo en la lista. En este caso, como estamos creando el primer nodo, no hay otro nodo después de él, por lo que lo dejamos apuntando a NULL. NULL significa "sin dirección" o "vacío".
return new_node;:

return: La función debe devolver algo. En este caso, estamos devolviendo el puntero al nodo recién creado.
new_node: Es el puntero que guarda la dirección del nodo que acabamos de crear.
Función main
c
Copy code
int main() {
    // Creamos algunos nodos
    t_list *node1 = create_node("Primer nodo");
    t_list *node2 = create_node("Segundo nodo");
    t_list *node3 = create_node("Tercer nodo");

    // Enlazamos los nodos
    node1->next = node2;  // El primer nodo apunta al segundo
    node2->next = node3;  // El segundo nodo apunta al tercero

    // El primer nodo es la cabeza de la lista
    t_list *begin_list = node1;

    // Llamamos a la función ft_list_size para contar los nodos
    printf("El tamaño de la lista es: %d\n", ft_list_size(begin_list));

    // Liberamos la memoria después de usarla (importante en C)
    free(node1);
    free(node2);
    free(node3);

    return 0;
}
int main():

main es el punto de entrada del programa. Es la función que se ejecuta primero cuando corres el programa.
t_list *node1 = create_node("Primer nodo");:

Aquí estamos llamando a la función create_node para crear un nodo que guarda el dato "Primer nodo". La dirección de este nodo se guarda en node1.
t_list *node2 = create_node("Segundo nodo");:

Similar a node1, estamos creando el segundo nodo con el dato "Segundo nodo" y guardando la dirección de ese nodo en node2.
t_list *node3 = create_node("Tercer nodo");:

Similar a los anteriores, creamos el tercer nodo con el dato "Tercer nodo" y guardamos su dirección en node3.
node1->next = node2;:

Esto significa que el primer nodo (node1) apunta al segundo nodo (node2) como su siguiente nodo. En otras palabras, estamos "conectando" el primer nodo al segundo.
node2->next = node3;:

Similar al paso anterior, el segundo nodo (node2) apunta al tercer nodo (node3) como su siguiente nodo.
t_list *begin_list = node1;:

begin_list es el primer nodo de la lista. Como node1 es el primer nodo, simplemente le decimos a begin_list que apunte a node1.
printf("El tamaño de la lista es: %d\n", ft_list_size(begin_list));:

Aquí estamos llamando a la función ft_list_size (que no hemos visto, pero cuenta cuántos nodos hay en la lista) y mostramos el tamaño en la pantalla.
free(node1); free(node2); free(node3);:

free se usa para liberar la memoria que hemos reservado con malloc. Es importante liberar la memoria cuando ya no la necesitamos para evitar que se quede ocupada sin uso.
return 0;:

Esto indica que el programa ha terminado correctamente. El 0 significa que no hubo errores.

t_list es el tipo de la variable, al igual que int o char.

En este caso, t_list es un tipo de dato personalizado que hemos definido usando la estructura struct.

t_list *begin_list = node1; es la declaración e inicialización de la variable begin_list en main.

Detalles de esta línea:
Declaración de begin_list:

t_list *begin_list: Estamos declarando una variable llamada begin_list, que es un puntero a t_list. Esto significa que begin_list va a almacenar la dirección de memoria de un nodo de tipo t_list.
Inicialización de begin_list:

= node1;: Aquí estamos inicializando begin_list con el valor de node1, que es un puntero al primer nodo de la lista. node1 fue creado previamente con create_node("Primer nodo").
¿Qué significa en términos de memoria?
node1 es un puntero que guarda la dirección de memoria de un nodo de la lista (el primer nodo).
Al hacer begin_list = node1;, estamos diciendo que begin_list también va a apuntar al mismo nodo (el primer nodo de la lista).
Es decir, begin_list y node1 son dos punteros que apuntan al mismo lugar en la memoria, que es el primer nodo de la lista.

En resumen:
Sí, esa línea es tanto la declaración como la inicialización de la variable begin_list, asignándole la dirección de memoria de node1 (que es el primer nodo de la lista).

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