/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getting_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 07:27:16 by mmarzouk          #+#    #+#             */
/*   Updated: 2020/12/01 14:29:22 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void affect_coulour(char **colour,char c,char **hold)
{
    int i;

    i = 0;
    while(i < 3)
    {
        if(!alldigs(colour[i],ft_strlen(colour[i])))
            ta_sir("wrong RGB value , there should be only numbers");
        i++;
    }
    if (c  == 'C')
    {
        g_tool.cr = ft_atoi(colour[0]);
        g_tool.cg = ft_atoi(colour[1]);
        g_tool.cb = ft_atoi(colour[2]);
    }
    else
    {
        g_tool.fr = ft_atoi(colour[0]);
        g_tool.fg = ft_atoi(colour[1]);
        g_tool.fb = ft_atoi(colour[2]);
    }
}