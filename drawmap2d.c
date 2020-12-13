/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 07:27:16 by mmarzouk          #+#    #+#             */
/*   Updated: 2020/12/13 13:14:52 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"



int		trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
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
			g_screen[(y * g_tool.xa + x)] = colour;
            //mlx_pixel_put(g_ptr, g_win, x, y, colour);
            y++;
        }
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
                square(j*g_tool.ts, i*g_tool.ts, g_tool.ts,trgb(0,g_tool.cr,g_tool.cg,g_tool.cb));
            else
                square(j*g_tool.ts, i*g_tool.ts, g_tool.ts,trgb(0,g_tool.fr,g_tool.fg,g_tool.fb));
            j++;
        }
        i++;
    }

//	mlx_clear_window(g_ptr, g_win);

}