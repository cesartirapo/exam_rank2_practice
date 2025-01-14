#include <unistd.h>
#include <string.h>

void    wdmatch(char *s1, char *s2)
{
    int i;
    int j;
    int found;
    i = 0;
    j = 0;
    while (s1[i])
    {
        found = 0;
        while (s2[j])
        {
            if (s1[i] == s2[j])
            {
                found = 1;
                break;
            }
            j++;
        }
        if (!found)
            break;
        i++;
    }
    if(s1[i] == '\0')
        write(1, s1, strlen(s1));
    write(1, "\n", 1);
}

int    main(int argc, char **argv)
{
    if(argc == 3)
        wdmatch(argv[1], argv[2]);
    else
        write(1, "\n", 1);
}