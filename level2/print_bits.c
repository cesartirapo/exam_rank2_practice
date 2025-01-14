#include <unistd.h>

void print_bits(unsigned char octet)
{
    int i = 7; // Inicializamos la variable i en 7 (porque el byte tiene 8 bits y el índice empieza en 0)

    while (i >= 0)  // Mientras i sea mayor o igual a 0, es decir, mientras queden bits por procesar
    {
        // Verificamos si el bit en la posición i es 1 o 0
        if (octet & (1 << i))  // Desplazamos el 1 a la posición i y hacemos una operación AND con octet
            write(1, "1", 1);  // Si el resultado es diferente de 0, es un 1, entonces lo imprimimos
        else
            write(1, "0", 1);  // Si el resultado es 0, es un 0, entonces lo imprimimos

        i--;  // Disminuimos i para procesar el siguiente bit
    }
}

/* Prueba con un ejemplo */
int main()
{
    unsigned char octet = 5;  // Ejemplo: 3 en binario es 00000011
    print_bits(octet);         // Imprime: 00000011
}