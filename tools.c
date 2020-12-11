/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 07:27:16 by mmarzouk          #+#    #+#             */
/*   Updated: 2020/12/04 19:52:27 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void doublefree(char **ptr)
{
    int i;
    
    if (ptr != NULL)
    {
        i = doublecount(ptr);
        while(i >= 0)
        {
            free(ptr[i]);
            i--;
        }
        free(ptr);
    }
    ptr = NULL;
}

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

int reversecheck(char *s,char *str)
{
    int i;
    int j;

    i = ft_strlen(s);
    j = ft_strlen(str);
    while(j != -1)
    {
        if (s[i] != str[j] || i < j)
            return(0);
        i--;
        j--;
    }
    return (1);
    
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