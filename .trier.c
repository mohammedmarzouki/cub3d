#include "libft/libft.h"
#include <stdio.h>

int doublecount(char **s)
{
    int i;

    i = 0;
    // if (s && *s)
    if (s)
    {
        while (s[i])
            i++;
    }
    return(i);
}

int countchars(char *s ,char c)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while(s[i])
    {
        if (s[i] == c)
            count++;
        i++;
    }
    return(count);
    
}
// int alldigs(char *s,int len)
// {
//     int i;

//     i = 0;
//     while (i < len && s)
//     {
//         if(!ft_isdigit(s[i]))
//             return(0);
//         i++;
//     }
//     return(1);
// }
int main()
{
    char **s;

    s = ft_split("c kdfv nelknn fff",' ');
    
    
    printf("%d\n",countchars("dgrg,sgaa,agrgrgarsgarg",','));
}