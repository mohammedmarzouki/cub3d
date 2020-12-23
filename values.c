/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 08:27:16 by mmarzouk          #+#    #+#             */
/*   Updated: 2020/12/23 18:37:26 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cube.h"
void    wall(void)
{
    int x;
    int y;
    
    x = g_map.nppx / g_tool.ts;
    y = g_map.nppy / g_tool.ts;
    if(!ft_strchr("1 2",g_map.map[y][x]))
    {
        x = g_map.ppx / g_tool.ts;
        y = g_map.nppy / g_tool.ts;
        if(!ft_strchr("1 2",g_map.map[y][x]))
        {
            x = g_map.nppx / g_tool.ts;
            y = g_map.ppy / g_tool.ts;
            if(!ft_strchr("1 2",g_map.map[y][x]))
            {                
                g_map.ppx = g_map.nppx;
                g_map.ppy = g_map.nppy;
            }
        }
    }
}
int is_wall(float x ,float y)
{
    float a;
    float b;
    
    a = x / g_tool.ts;
    b = y / g_tool.ts;  
    x = (x + 1) / g_tool.ts;
    y = y / g_tool.ts;
    if(!ft_strchr("1 2",g_map.map[(int)b][(int)a]) && (!ft_strchr("1 2",g_map.map[(int)y][(int)x])))
    {
        return(0);
    }
    return(1);
}
void    render(void)
{
    init_values();
	drawmap();
	ft_circle(g_map.ppx, g_map.ppy,trgb(0,g_tool.fr,g_tool.fg,g_tool.fb));
	ft_fov();
    mlx_put_image_to_window(g_ptr, g_win, g_image, 0 ,0 );
}
void correcting_angle(void)
{
    if(g_map.pdrct > (2 * M_PI))
        g_map.pdrct -= 2 * M_PI;
    else if (g_map.pdrct < 0)
        g_map.pdrct += 2 * M_PI;
}
void   player_position(int *x, int *y)
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
            {
                g_map.ppx = (j*g_tool.ts)+(g_tool.ts/2);
                g_map.ppy = (i*g_tool.ts)+(g_tool.ts/2);
                *x = j;
                *y = i;
                return;
            }
            j++;
        }
        i++;
    }
}
void init_values(void)
{
    int i;
    int j;

    player_position(&j, &i);
    if(g_map.map[i][j] == 'N')
        g_map.pdrct = 3*M_PI/2;
    else if (g_map.map[i][j] == 'S')
        g_map.pdrct = M_PI/2;
    else if (g_map.map[i][j] == 'W')
        g_map.pdrct = M_PI;
    else if (g_map.map[i][j] == 'E')
        g_map.pdrct = 0;
}