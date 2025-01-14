
void    inter(char *s1, char *s2)
{
    int i;
    int j;
    unsigned char seen[256] = {0};//Declara un arreglo seen de tamaño 256 (uno para cada posible carácter en la tabla ASCII). Inicializa todos los elementos a 0. Este arreglo sirve para marcar qué caracteres ya se han encontrado y mostrado.
    //Nota: unsigned char asegura que el índice es un número no negativo, necesario para trabajar con todos los caracteres de la tabla ASCII.
    i = 0;
    while (s1[i])
    {
        j = 0;
        while (s2[j])
        {
            if (s1[i] == s2[j])
            {
                if (!seen[(unsigned char)s1[i]])//s1[i] se convierte explícitamente a unsigned char para asegurar que el índice del arreglo seen[] sea tratado correctamente como un valor no negativo. Este paso es importante porque s1[i] puede ser un valor negativo si se trata como signed char en algunas plataformas, y queremos asegurarnos de que el índice en seen[] siempre esté dentro del rango 0-255.
                //si seen[s[1]] es 0, es decir, no se ha visto, entonces !seen convierte 1 y se ejecuta el buble. En realidad es una mierda.
                //más fácil sería decir if(seen[(unsigned char)s1[i]] == 0)
                {
                    write(1, &s1[i], 1);
                    seen[(unsigned char)s1[i]] = 1;
                }
                break;
            }
            j++;
        }
        i++;
    }
    write(1, "\n", 1);
}

int    main(int argc, char **argv)
{
    if(argc == 3)
        inter(argv[1], argv[2]);
    else
        write(1, "\n", 1);
}