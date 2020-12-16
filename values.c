/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 08:27:16 by mmarzouk          #+#    #+#             */
/*   Updated: 2020/12/16 16:55:11 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cube.h"

void    render(void)
{
    init_values();
    drawmap();
    drawplayer();
    draw_line(g_map.ppx,g_map.ppy,g_map.ppy+cos(g_map.pdrct)*30 , g_map.ppx + sin(g_map.pdrct)*30);
    //draw_line(0,100,0,200);
    mlx_put_image_to_window(g_ptr, g_win, g_image, 0 ,0 );
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
    printf("%d|||%d\n",g_map.ppx,g_map.ppy);
    if(g_map.map[i][j] == 'N')
        g_map.pdrct = 3*M_PI/4;
    else if (g_map.map[i][j] == 'S')
        g_map.pdrct = M_PI/2;
    else if (g_map.map[i][j] == 'W')
        g_map.pdrct = M_PI;
    else if (g_map.map[i][j] == 'E')
        g_map.pdrct = 0;
    printf("%f\n",g_map.pdrct);
}