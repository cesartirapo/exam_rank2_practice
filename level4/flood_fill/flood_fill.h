#ifndef T_POINT_FLOOD_FILL
# define T_POINT_FLOOD_FILL

typedef struct 	s_point {//s_: El prefijo s_ generalmente indica que la variable o tipo es una estructura. Esto ayuda a que el programador reconozca rápidamente que se está trabajando con una estructura (que agrupa varios datos) en lugar de una variable simple de tipo primitivo como int o char.
    int 		x;				// x : Width  | x-axis
    int 		y;				// y : Height | y-axis
} 				t_point;//t_: El prefijo t_ se usa para indicar que el tipo es un alias de tipo (definido por el usuario), no necesariamente una estructura. Esto incluye tipos como estructuras, enumeraciones, uniones o cualquier tipo definido a través de typedef.

// Prototipo de la función fill (declaración)
void fill(char **tab, t_point size, t_point cur, char to_fill);

// Prototipo de la función flood_fill (declaración)
void flood_fill(char **tab, t_point size, t_point begin);

#endif

/*
 Este código dentro del archivo .h sirve para definir un tipo de dato estructurado llamado t_point, el cual está compuesto por dos enteros (x e y) que representan coordenadas en un plano 2D. El archivo .h es un archivo de encabezado y generalmente se usa para proporcionar las definiciones de tipos, funciones y variables que se usarán en otros archivos fuente .c.

Desglosando la función de este archivo .h:
Definición de la estructura t_point:

El tipo t_point es una estructura que contiene dos campos:
x: Una variable entera que representa la coordenada en el eje horizontal (o el "ancho").
y: Una variable entera que representa la coordenada en el eje vertical (o la "altura").
Al definir t_point en un archivo .h, el propósito es permitir que este tipo estructurado sea utilizado en el código de otras partes del proyecto, haciendo más fácil el manejo de coordenadas o puntos en un espacio 2D.

Uso de #ifndef, #define y #endif:

Estas directivas se utilizan para prevenir la inclusión múltiple del archivo de encabezado.
Si este archivo .h es incluido en varios archivos .c dentro del proyecto, el bloque entre #ifndef y #endif asegura que la estructura solo se defina una vez, evitando conflictos o errores de compilación debido a definiciones duplicadas.
*/