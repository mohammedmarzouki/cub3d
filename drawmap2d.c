/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 07:27:16 by mmarzouk          #+#    #+#             */
/*   Updated: 2020/12/23 18:30:41 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"



int		trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}


void    floor_ceiling(void)
{
    int x;
    int y;
    int hold;
    int colour;


    y = 0;
    hold = g_tool.ya / 2;
    colour = trgb(0,g_tool.cr,g_tool.cg,g_tool.cb);
    while(y < g_tool.ya)
    {
        while (y < hold)
        {
            x = 0;
            while (x < g_tool.xa)
            {
                g_screen[(y * g_tool.xa + x)] = colour;
                x++;
            }
            y++;
        }
        colour = trgb(0,g_tool.fr,g_tool.fg,g_tool.fb);
        hold = g_tool.ya;
    }
    
}

void square(int x,int y,int lenght,int colour)
{
    int xh;
    int yh;

    xh = x;
    yh = y;
    while(x < lenght + xh)
    {
        y = yh;
        while(y < lenght + yh)
        {
            if(x == xh || y == yh || x == xh + lenght-1|| y == yh + lenght -1)
			    g_screen[((int)(y* DIV) * g_tool.xa + (int)(x* DIV))] = 0x000000;
            else
			    g_screen[((int)(y* DIV) * g_tool.xa + (int)(x* DIV))] = colour;
                
            //mlx_pixel_put(g_ptr, g_win, x, y, colour);
            y++;
        }
        // g_screen[(y-1 * g_tool.xa + x)] = 0x000000;
        x++;
    }
}
void    drawmap(void)
{
    int i;
    int j;

    i = 0;
    while(g_map.map[i])
    {
        j = 0;
        while(g_map.map[i][j])
        {
            if(g_map.map[i][j] == '1')
                square(j*TS, i*TS, TS,trgb(0,g_tool.cr,g_tool.cg,g_tool.cb));
            else
                square(j*TS, i*TS, TS,trgb(0,g_tool.fr,g_tool.fg,g_tool.fb));
            j++;
        }
        i++;
    }
}
void drawplayer(void)
{
    int i;
    int j;

    i = 0;
    while(g_map.map[i])
    {
        j = 0;
        while(g_map.map[i][j])
        {
            if(ft_strchr("NWSE",g_map.map[i][j]))
                ft_circle(g_map.ppx, g_map.ppy,trgb(0,g_tool.fr,g_tool.fg,g_tool.fb));
            j++;
        }
        i++;
    }
}