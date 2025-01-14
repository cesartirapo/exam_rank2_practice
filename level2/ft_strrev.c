
char    *ft_strrev(char *str)

{
    int len;
    int i;
    char    temp;
    len = 0;
    i = 0;
    while (str[len])
        len++;
    while(i < len - 1)//último carácter antes del \0
    {
        temp = str[i];
        str[i] = str[len - 1];
        str[len - 1] = temp;
        i++;
        len--;
    }
    return (str);
}