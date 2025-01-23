//Contar palabras.
//Asignar memoria.
//Copiar palabras.
//Realizar el split y devolver el arreglo.
#include <stdio.h>
#include <stdlib.h>

void ft_copy(char *ptr, char *s, int start)
{
    int i = 0;
    while(s[i] && s[i] != ' ')
    {
        ptr[i] = s[start];
        i++;
        start++;
    }
    ptr[i] = '\0';
}

char *ft_memory_ptr(int len)//Podrias tener una unica funcion para asignar memoria con este prototipo void *ft_memory(int size, int is_array). Mira la funcion test.c
{
    char *ptr = (char *)malloc ((len + 1) * sizeof(char));
    if(!ptr)
        return NULL;
    return ptr;
}

char **ft_memory_array(int word_count)
{
    char **array = (char **)malloc ((word_count + 1) * sizeof(char *));
    if(!array)
        return NULL;
    return array;
}

int ft_count(char *s, char c)
{
    int word_count = 0;
    int i = 0;
    while(s[i])
    {
        while(s[i] == c)
            i++;
        if(s[i] != '\0')
        {
            word_count++;
            while(s[i] && s[i] != c)
                i++;
        }    
    }
    return word_count;
}

char **ft_split(char *s, char c)
{
    if(!s)
        return NULL;

    int word_count = ft_count(s, c);

    char **array = ft_memory_array(word_count);

    int i = 0;
    int index = 0;
    while(s[i])
    {
        while(s[i] == c)
            i++;
        if(s[i] != '\0')
        {
            int start = i;
            while(s[i] && s[i] != c)
                i++;
            int len = i - start;
            array[index] = ft_memory_ptr(len);
            if(!array[index])
            {
                int j = 0;
                while(j < index)
                {
                    free(array[j]);
                }
                free(array);
                return NULL;
            }
            ft_copy(array[index], s, start);
        }
        index++;
    }
    array[index] = NULL;
    return array;
}

int main(int ac, char **av)
{
    char **array = ft_split(av[1], ' ');
    int i = 0;
    while(array[i])
    {
        printf("%s\n", array[i]);
        i++;
    }
    
    i = 0;
    while(array[i])
    {
        free(array[i]);
        i++;
    }
    free(array);
    return 0;
}