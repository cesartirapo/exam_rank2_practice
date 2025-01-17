#ifndef FT_LIST_H   // Evita que el archivo se incluya más de una vez en el código
# define FT_LIST_H   // Define un nombre único para este archivo, de modo que se use una sola vez

// Definición de la estructura 't_list', que representa un nodo de una lista enlazada
//El problema surge si un archivo .h se incluye dos veces en el mismo archivo .c
//En un proyecto de C, el compilador toma todos los archivos .c y los compila por separado. Luego, los enlaza (une) para formar el programa completo. Por lo tanto, cada archivo .c es considerado "un archivo final" en este proceso de compilación. Si tienes archivos como main.c, ft_list.c, utils.c, etc., el compilador tratará cada uno de estos archivos como un archivo separado durante la compilación.
//¿Por qué la inclusión múltiple puede ser un problema? Cuando usas #include en tu código, el compilador copiará y pegará el contenido del archivo .h dentro de tu archivo .c cada vez que lo encuentres. Si no tienes las protecciones adecuadas, el compilador puede incluir el mismo archivo .h más de una vez en un solo archivo .c, lo que provoca duplicaciones.
typedef struct s_list
{
    struct s_list *next; // Puntero que guarda la dirección del siguiente nodo en la lista. El puntero apunta a un nodo, que es una estructura del tipo s_list, por lo que ese nodo tambien tendra un puntero next y un puntero data. En conclusion, este campo permite "enlazar" un nodo con otro, creando la lista
//Si 'next' es NULL, significa que este es el último nodo de la lista y que no apunta a otro nodo de tipo s_list.

    void *data;         // Puntero a los datos almacenados en el nodo. El tipo 'void *' significa que puede apuntar a cualquier tipo de dato
                        // Esto hace que la lista sea flexible y pueda almacenar cualquier tipo de información, por ejemplo, enteros, cadenas, estructuras complejas, etc.

} t_list;              // 't_list' es el alias para esta estructura, que representa un nodo en la lista. El prefijo t_ es una convención en C que indica que el nombre representa un tipo definido por el programador (de "type"). Este prefijo ayuda a diferenciarlo de otras cosas en tu código, como variables, funciones o macros. Ejemplo:
//t_list: Significa "tipo lista", dejando claro que es un tipo de dato que tú definiste.
//s_list: Significa "estructura lista", lo cual es el nombre técnico que le das al definirla como una estructura (struct).
//¿Por qué usar convenciones? Claridad: Cuando ves t_ en el código, sabes rápidamente que es un alias de tipo, no una variable o función.

#endif  // Fin de la protección de preprocesador, asegura que este bloque de código no se repita
