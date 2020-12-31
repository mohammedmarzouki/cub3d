/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getting_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 07:27:16 by mmarzouk          #+#    #+#             */
/*   Updated: 2020/12/04 14:53:12 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void affect_coulour(char **colour,char c,char **hold)
{
    int i;

    i = 0;
    while(i < 3)
    {
        if(!alldigs(colour[i], ft_strlen(colour[i])))
            ta_sir("wrong RGB value , there should be only numbers");
        i++;
    }
    if (c  == 'C' && g_tool.cflag == 0)
    {
        g_tool.cflag = 1;
        g_tool.cr = ft_atoi(colour[0]);
        g_tool.cg = ft_atoi(colour[1]);
        g_tool.cb = ft_atoi(colour[2]);
    }
    else if(c == 'F' && g_tool.fflag == 0)
    {
        g_tool.fflag = 1;
        g_tool.fr = ft_atoi(colour[0]);
        g_tool.fg = ft_atoi(colour[1]);
        g_tool.fb = ft_atoi(colour[2]);
    }
    else
        ta_sir("colour already taken");
    //free colour and hold
}

void    ptr_wh(int x,int y)
{
    //printf("%d|WH|%d\n",x,y);
	if (!ft_memcmp(g_tool.vars.hold[0], "NO", 2) )
    {
		g_xpm.now = x;
		g_xpm.noh = y;
        // printf("%d|NO|%d\n",g_xpm.now,g_xpm.noh);
    }
	else if (!ft_memcmp(g_tool.vars.hold[0], "EA", 2) )
    {
		g_xpm.eaw = x;
		g_xpm.eah = y;
        // printf("%d|EA|%d\n",g_xpm.eaw,g_xpm.eah);
    }
	else if (!ft_memcmp(g_tool.vars.hold[0], "SO", 2) )
    {
		g_xpm.sow = x;
		g_xpm.soh = y;
        // printf("%d|SO|%d\n",g_xpm.sow,g_xpm.soh);
    }
	else if (!ft_memcmp(g_tool.vars.hold[0], "WE", 2) )
    {
		g_xpm.wew = x;
		g_xpm.weh = y;
        // printf("%d|WE|%d\n",g_xpm.wew,g_xpm.weh);
    }
	else if (!ft_memcmp(g_tool.vars.hold[0], "S", 1))
    {
		g_xpm.sw = x;
		g_xpm.sh = y;
        // printf("%d|S|%d\n",g_xpm.sw,g_xpm.sh);
    }
}
