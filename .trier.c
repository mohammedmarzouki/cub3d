#include "libft/libft.h"
#include <stdio.h>

int doublecount(char **s)
{
    int i;

    i = 0;
    if (s)
    {
        while (s[i])
            i++;
    }
    return(i);
}

int alldigs(char *s,int len)
{
    int i;

    i = 0;
    while (i < len && s)
    {
        if(!ft_isdigit(s[i]))
            return(0);
        i++;
    }
    return(1);
}
int main()
{
    char *s;

    s = "l654568";
    printf("%d\n",alldigs(s,ft_strlen(s)));
}