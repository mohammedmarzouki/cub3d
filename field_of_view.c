/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_of_view.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 11:16:16 by mmarzouk          #+#    #+#             */
/*   Updated: 2020/12/22 20:35:40 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void ft_fov(void)
{
    float check;

    g_tool.cntplyr = 0;
    g_map.rayd = g_map.pdrct - (FOV / 2);
    check = g_map.rayd ;
    while (check < g_map.pdrct + (FOV / 2) && g_tool.cntplyr < g_tool.xa)
    {
        raycast();
        draw_walls(g_map.wx,g_map.wy);
        // a_line(g_map.ppx,g_map.ppy,g_map.wx,g_map.wy);
        g_map.rayd += FOV/g_tool.xa;
        check += FOV/g_tool.xa;
        if(g_map.rayd > (2 * M_PI))
            g_map.rayd -= 2 * M_PI;
        else if (g_map.rayd < 0)
            g_map.rayd += 2 * M_PI;
        g_tool.cntplyr++;
    }
    g_tool.wi = 0;
}

void raycast(void)
{
    float horzhitdistance;
    float verthitdistance;

    ray_direction();
    horzhitdistance = (casth())
      ? distance(g_map.ppx, g_map.ppy, g_map.hwx, g_map.hwy)
       : MAXFLOAT;
    verthitdistance = (castv())
       ? distance(g_map.ppx, g_map.ppy, g_map.vwx, g_map.vwy)
       : MAXFLOAT;
    g_map.wx = (horzhitdistance < verthitdistance) ? g_map.hwx : g_map.vwx;
    g_map.wy = (horzhitdistance < verthitdistance) ? g_map.hwy : g_map.vwy;
    g_map.dis = (horzhitdistance < verthitdistance) ? horzhitdistance : verthitdistance;
    g_map.hov = (horzhitdistance < verthitdistance) ? 1 : 0;
    
}
void ray_direction(void)
{
    g_map.down = (g_map.rayd > 0 && g_map.rayd < M_PI) ? 1 : 0; 
    g_map.up = (g_map.down)? 0 : 1;
    g_map.right = (g_map.rayd < M_PI/2 || g_map.rayd > 3 * M_PI/2) ? 1 : 0;
    g_map.left = (g_map.right) ? 0 : 1;
}
int casth(void)
{
    float xintercept, yintercept;
    float xstep, ystep;
    float nextHorzTouchX ;
    float nextHorzTouchY ;

    yintercept = floor(g_map.ppy / TS) * TS;
    yintercept += g_map.down ? TS : 0;
    xintercept = g_map.ppx + (yintercept - g_map.ppy) / tan(g_map.rayd);
    ystep = TS;
    ystep *= g_map.up ? -1 : 1;
    xstep = TS / tan(g_map.rayd);
    xstep *= (g_map.left && xstep > 0) ? -1 : 1;
    xstep *= (g_map.right && xstep < 0) ? -1 : 1;
    nextHorzTouchX = xintercept;
    nextHorzTouchY = yintercept;
    while (nextHorzTouchX > 0 && nextHorzTouchX < g_tool.cols * TS
        && nextHorzTouchY > 0 && nextHorzTouchY < g_tool.rows * TS)
    {
        if (is_wall(nextHorzTouchX, nextHorzTouchY - (g_map.up ? 1 : 0))) 
        {
            g_map.hwx = nextHorzTouchX;
            g_map.hwy = nextHorzTouchY;
            return (1);
        } 
        else 
        {
            nextHorzTouchX += xstep;
            nextHorzTouchY += ystep;
        }
    }
    return(0);
}
int castv(void)
{
    float xintercept, yintercept;
    float xstep, ystep;
    float nextVertTouchX ;
    float nextVertTouchY ;

    xintercept = floor(g_map.ppx / TS) * TS;
    xintercept += g_map.right ? TS : 0;
    yintercept = g_map.ppy + (xintercept - g_map.ppx) * tan(g_map.rayd);
    xstep = g_map.left ? -1 * TS : TS;
    ystep = TS * tan(g_map.rayd);
    ystep *= (g_map.up && ystep > 0) ? -1 : 1;
    ystep *= (g_map.down && ystep < 0) ? -1 : 1;
    nextVertTouchX = xintercept;
    nextVertTouchY = yintercept;
    while (nextVertTouchX >= 0 && nextVertTouchX <= g_tool.cols * TS && nextVertTouchY >= 0 && nextVertTouchY <= g_tool.rows * TS) 
    {
        if (is_wall(nextVertTouchX - (g_map.left ? 1 : 0), nextVertTouchY)) 
        {
            g_map.vwx = nextVertTouchX;
            g_map.vwy = nextVertTouchY;
            return(1);
        } 
        else 
        {
            nextVertTouchX += xstep;
            nextVertTouchY += ystep;
        }
    }
    return(0);
}