
#include <stdio.h>


char *ft_strrev(char *str)
{
	int i = 0;
	int len = 0;
	char temp;
	while(str[len])
		len++;
	while(i < (len / 2))
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
		i++;
	}
	return str;
}

int main()
{
	char str[] = "abc";
	ft_strrev(str);
	printf("%s", str);
}
