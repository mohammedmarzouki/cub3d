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
    g_tool.cntplyr = 0;
    g_map.rayd = g_map.pdrct - (FOV / 2);
    while(g_map.rayd < g_map.pdrct + (FOV / 2) && g_tool.cntplyr <= g_tool.xa)
    {
        raycast();
        a_line(g_map.ppx,g_map.ppy,g_map.wx,g_map.wy);
        g_map.rayd += FOV/g_tool.xa;
        g_tool.cntplyr++;
    }
}

void raycast(void)
{
    ray_direction();
   float horzHitDistance = (casth())
      ? distance(g_map.ppx, g_map.ppy, g_map.hwx, g_map.hwy)
       :INT32_MAX;
   float vertHitDistance = (castv())
       ? distance(g_map.ppx, g_map.ppy, g_map.vwx, g_map.vwy)
       :INT32_MAX;
    g_map.wx = (horzHitDistance < vertHitDistance) ? g_map.hwx : g_map.vwx;
    g_map.wy = (horzHitDistance < vertHitDistance) ? g_map.hwy : g_map.vwy;
    g_map.dis = (horzHitDistance < vertHitDistance) ? horzHitDistance : vertHitDistance;
    // wasHitVertical = (vertHitDistance < horzHitDistance)
}
void ray_direction(void)
{
    if(g_map.rayd > 0 && g_map.rayd < M_PI)
        g_map.down = 1;
    else
        g_map.down = 0;
    if (g_map.down)    
        g_map.up =  0;
    else
        g_map.up =  1;
    if(g_map.rayd < M_PI/2 || g_map.rayd > 3 * M_PI/2)
        g_map.right = 1;
    else
        g_map.right = 0;
    if (g_map.right)
        g_map.left = 0;
    else
        g_map.left = 1;
}
int casth(void)
{
    float xintercept, yintercept;
    float xstep, ystep;
    float nextHorzTouchX ;
    float nextHorzTouchY ;

    ///////////////////////////////////////////
    // HORIZONTAL RAY-GRID INTERSECTION CODE //
    ///////////////////////////////////////////

    // Find the y-coordinate of the closest horizontal grid intersenction
    yintercept = floor(g_map.ppy / TS) * TS;
    yintercept += g_map.down ? TS : 0;

    // Find the x-coordinate of the closest horizontal grid intersection
    xintercept = g_map.ppx + (yintercept - g_map.ppy) / tan(g_map.rayd);

    // Calculate the increment xstep and ystep
    ystep = TS;
    ystep *= g_map.up ? -1 : 1;

    xstep = TS / tan(g_map.rayd);
    xstep *= (g_map.left && xstep > 0) ? -1 : 1;
    xstep *= (g_map.right && xstep < 0) ? -1 : 1;

    nextHorzTouchX = xintercept;
    nextHorzTouchY = yintercept;

    // Increment xstep and ystep until we find a wall
    while (nextHorzTouchX >= 0 && nextHorzTouchX <= g_tool.cols * TS && nextHorzTouchY >= 0 && nextHorzTouchY <= g_tool.rows * TS) 
    {
        if (is_wall(nextHorzTouchX, nextHorzTouchY - (g_map.up ? 1 : 0))) {
            g_map.hwx = nextHorzTouchX;
            g_map.hwy = nextHorzTouchY;
            return (1);
        } else {
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
    ///////////////////////////////////////////
    // VERTICAL RAY-GRID INTERSECTION CODE   //
    ///////////////////////////////////////////

    // Find the x-coordinate of the closest vertical grid intersenction
    xintercept = floor(g_map.ppx / TS) * TS;
    xintercept += g_map.right ? TS : 0;

    // Find the y-coordinate of the closest vertical grid intersection
    yintercept = g_map.ppy + (xintercept - g_map.ppx) * tan(g_map.rayd);

    // Calculate the increment xstep and ystep
    xstep = TS;
    xstep *= g_map.left ? -1 : 1;

    ystep = TS * tan(g_map.rayd);
    ystep *= (g_map.up && ystep > 0) ? -1 : 1;
    ystep *= (g_map.down && ystep < 0) ? -1 : 1;

    nextVertTouchX = xintercept;
    nextVertTouchY = yintercept;

    // Increment xstep and ystep until we find a wall
    while (nextVertTouchX >= 0 && nextVertTouchX <= g_tool.cols * TS && nextVertTouchY >= 0 && nextVertTouchY <= g_tool.rows * TS) 
    {
        if (is_wall(nextVertTouchX - (g_map.left ? 1 : 0), nextVertTouchY)) {
            g_map.vwx = nextVertTouchX;
            g_map.vwy = nextVertTouchY;
            return(1);
        } else {
            nextVertTouchX += xstep;
            nextVertTouchY += ystep;
        }
    }
    return(0);
}