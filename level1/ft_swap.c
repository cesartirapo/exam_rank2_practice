
void    ft_swap(int *a, int *b)
{
    int    c;
    c = *a;//*a = valor apuntado por a
    *a = *b;
    *b = c;
}

int main()
{
    int    a;
    int    b;
    a = 1;
    b = 2;
    ft_swap(&a, &b);//&a = dirección de la variable a
    return (0);
}