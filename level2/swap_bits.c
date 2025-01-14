#include <stdio.h> // Incluye funciones estándar como printf

// Función que intercambia las mitades de un byte
unsigned char swap_bits(unsigned char octet)
{
    // Desplaza los 4 bits altos hacia los bajos y viceversa, luego los combina
    return ((octet >> 4) | (octet << 4));
}

int main()
{
    unsigned char byte = 0x41; // Declaramos un byte con el valor 0x41 (hexadecimal)
    // Este es el número 01000001 en binario

    // Llamamos a la función swap_bits y guardamos el resultado
    unsigned char swapped = swap_bits(byte);

    // Mostramos el resultado original y el modificado
    printf("Original: 0x%X (binario: 01000001)\n", byte);
    printf("Intercambiado: 0x%X (binario: 00010100)\n", swapped);

    return 0; // Indica que el programa terminó correctamente
}
/*Supongamos que tenemos el siguiente byte:

makefile
Copy code
octet = 01000001
Paso 1: Desplazar a la derecha (octet >> 4)
Cuando desplazamos los bits a la derecha 4 posiciones:

scss
Copy code
01000001  (octet original)
↓
00000100  (desplazado 4 bits a la derecha)
¿Qué sucede?
Los primeros 4 bits (0100) se mueven a las 4 posiciones más bajas.
Los últimos 4 bits (0001) se pierden, ya que ya no quedan en el byte después del desplazamiento.
A la izquierda, se rellenan con ceros.
Resultado después de octet >> 4:

Copy code
00000100
Paso 2: Desplazar a la izquierda (octet << 4)
Ahora, desplazamos los bits a la izquierda 4 posiciones:

scss
Copy code
01000001  (octet original)
↑
00010000  (desplazado 4 bits a la izquierda)
¿Qué sucede?
Los últimos 4 bits (0001) se mueven a las 4 posiciones más altas.
Los primeros 4 bits (0100) se pierden, ya que ya no quedan en el byte después del desplazamiento.
A la derecha, se rellenan con ceros.
Resultado después de octet << 4:

Copy code
00010000
Paso 3: Combinar los resultados
Finalmente, cuando combinamos los dos resultados con el operador | (OR bit a bit):

octet >> 4 = 00000100
octet << 4 = 00010000
Usamos el operador | (OR):

markdown
Copy code
00000100
OR
00010000
-----------
00010100
Resultado final:
Copy code
00010100
