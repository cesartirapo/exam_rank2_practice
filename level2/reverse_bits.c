#include <stdio.h> // Para usar printf

unsigned char reverse_bits(unsigned char octet)
{
    int i = 8;                   // Un byte tiene 8 bits
    unsigned char res = 0;       // Variable para almacenar el resultado invertido. En esencia, se crea esta variable con valor 0, que en binario es 00000000

    while (i > 0)                // Iterar por cada bit del byte
    {
        res = res << 1;          // Desplazar los bits de res hacia la izquierda. Esto se hace porque iremos añadiendo a la derecha del todo de res los bits de octet. Cada vez que añadamos un bit, lo moveremos a la izquierda para hacer hueco al siguiente.
        res = res | (octet & 1); // Extraer el bit menos significativo de octet y añadirlo a res. Esto "octet & 1" compara octet con 1, que en binario es 00000001. Cuando el bit de octet sea 1, el resultado será 1 y se sumara a res. Después de obtener el último bit de octet, lo pegamos en el bit menos significativo de res (el bit más a la derecha) usando el operador OR (|). Este operador asegura que no borremos los bits previos de res. Si el bit obtenido es 1, se coloca un 1 en el bit correspondiente de res. Si, por jemplo, res = 00000000 y el bit obtenido de octet es 1, entonces res = res | 1 se convierte en 00000001.
        octet = octet >> 1;      // Desplazar octet hacia la derecha para procesar el siguiente bit de octet.
        i--;                     // Reducir el contador de bits
    }

    return res;                  // Devolver el byte invertido
}

int main()
{
    unsigned char octet = 38; // Valor en decimal (38 = 00100110 en binario)
    unsigned char reversed = reverse_bits(octet);

    printf("Original: %u (binario: 00100110)\n", octet);
    printf("Reversed: %u (binario: 01100100)\n", reversed);

    return 0;
}