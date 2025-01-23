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

void *ft_memory(int size, int is_array)//El prototipo void *ft_memory(int size, int is_array) devuelve un puntero genérico (void *), que puede ser interpretado de diferentes formas, como char ** o char *, dependiendo de cómo se use en el contexto. Al devolver void *, puedes hacer un cast a cualquier tipo de puntero cuando lo asignes.
{
    if(is_array)
    {
        void *array = malloc((size + 1) * sizeof(char *));
        if (!array)
            return NULL;
        return array;
    }
    else
    {
        void *ptr = malloc((size + 1) * sizeof(char));
        if (!ptr)
            return NULL;
        return ptr;
    }
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
    if (!s)
        return NULL;

    int word_count = ft_count(s, c);

    char **array = ft_memory(word_count, 1);
    if (!array)
        return NULL;

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
            array[index] = ft_memory(len, 0);
            if (!array[index])
            {
                for (int j = 0; j < index; j++)
                    free(array[j]);
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