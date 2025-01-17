#include <unistd.h>

void    inter(char *s1, char *s2)
{
	char unsigned seen[128] = {0};
	int i = 0;
	while(s1[i])
	{	
		int j = 0;
		while(s2[j])
		{
			if(s1[i] == s2[j])
			{
				if(!seen[s1[i]])
				{
					write(1, &s1[i], 1);
					seen[s1[i]] = 1;
				}
				break;
			}
			j++;
		}
		i++;
	}
}
int main(int ac, char **av)
{
	inter(av[1], av[2]);
}
	
