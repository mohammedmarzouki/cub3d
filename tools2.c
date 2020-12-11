/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 07:27:16 by mmarzouk          #+#    #+#             */
/*   Updated: 2020/12/09 11:11:55 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int alldone(void)
{
    if(g_tool.cflag && g_tool.fflag && g_tool.resflag)
    {
        if(g_xpm.ea && g_xpm.no && g_xpm.s && g_xpm.so && g_xpm.we)
            return(1);
    }
    return(0);
}

int allspaces(char *s)
{
    int i;

    i = 0;
    while(s[i])
    {
        if (s[i] != ' ')
            return(0);
        i++;
    }
    if (i)
        return(1);
    return(0);
}

int itismap(char *s)
{
    int i;
    
    i = 0;
    while(s[i])
    {
        if (!ft_strchr("012 NSEW",s[i]))
            ta_sir("a line doesn't make sence");
        i++;
    }
    if(i)
        g_tool.readingmap = 1;
    else
        return(0);
    return(1);
}

void save_map(char *s)
{
    char *carry;
    char *tmp;
    if(ft_strchr(s,'N') || ft_strchr(s,'S') 
        || ft_strchr(s,'E') || ft_strchr(s,'W'))
    {
        if (g_tool.cntplyr)
            ta_sir("multiple players in the map");   
        else
            g_tool.cntplyr = 1;
    }
    carry = ft_strjoin("\n",s);
    tmp = g_tool.vars.carrier;
    g_tool.vars.carrier = ft_strjoin(g_tool.vars.carrier,carry);
    free (tmp);
    free (carry);
}