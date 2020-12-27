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
    //float hold;

    g_tool.cntplyr = 0;
    hold = g_map.pdrct - (FOV / 2);
    while(hold < g_map.pdrct + (FOV / 2) && g_tool.cntplyr <= g_tool.xa)
    {
        draw_line(g_map.ppx,g_map.ppy,g_map.ppx+cos(hold)
        *INT16_MAX , g_map.ppy + sin(hold)*INT16_MAX);
        // printf("****%f****\n",g_map.pdrct + (FOV / 2));
        // printf("//// %f/////\n",hold);
        hold += FOV/g_tool.xa;
        g_tool.cntplyr++;
    }
}

void raycast(void)
{
    ray_direction();

////////////////////////////////////////////////////////////////////////////////////////////////////////
//    // Calculate both horizontal and vertical distances and choose the smallest value
//    float horzHitDistance = (foundHorzWallHit)
//       ? distance(g_map.ppx, g_map.ppy, horzWallHitX, horzWallHitY)
//        :INT32_MAX;
//    float vertHitDistance = (foundVertWallHit)
//        ? distance(g_map.ppx, g_map.ppy, vertWallHitX, vertWallHitY)
//        :INT32_MAX;
    // only store the smallest of the distances
    // wallHitX = (horzHitDistance < vertHitDistance) ? horzWallHitX : vertWallHitX;
    // wallHitY = (horzHitDistance < vertHitDistance) ? horzWallHitY : vertWallHitY;
    // distance = (horzHitDistance < vertHitDistance) ? horzHitDistance : vertHitDistance;
    // wasHitVertical = (vertHitDistance < horzHitDistance);
////////////////////////////////////////////////////////////////////////////////////////////////////////
}
void ray_direction(void)
{
    g_map.down = 0;
    if(g_map.rayd > 0 && g_map.rayd < M_PI)
        g_map.down = 1;
    g_map.up = g_map.down ? 0 : 1;
    g_map.right = 0;
    if(g_map.rayd > M_PI/2 || g_map.rayd < 3 * M_PI/2)
        g_map.right = 1;
    g_map.left = g_map.right ? 0 : 1;
}
void casth(void)
{
    float xintercept, yintercept;
    float xstep, ystep;

    ///////////////////////////////////////////
    // HORIZONTAL RAY-GRID INTERSECTION CODE //
    ///////////////////////////////////////////
    int foundHorzWallHit = 0;
    float horzWallHitX = 0;
    float horzWallHitY = 0;

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

    float nextHorzTouchX = xintercept;
    float nextHorzTouchY = yintercept;

    // Increment xstep and ystep until we find a wall
    while (nextHorzTouchX >= 0 && nextHorzTouchX <= g_tool.xa && nextHorzTouchY >= 0 && nextHorzTouchY <= g_tool.ya) {
        if (is_wall(nextHorzTouchX, nextHorzTouchY - (g_map.up ? 1 : 0))) {
            foundHorzWallHit = 1;
            horzWallHitX = nextHorzTouchX;
            horzWallHitY = nextHorzTouchY;
            return;
        } else {
            nextHorzTouchX += xstep;
            nextHorzTouchY += ystep;
        }
    }
    

}
void castv(void)
{
    float xintercept, yintercept;
    float xstep, ystep;
    ///////////////////////////////////////////
    // VERTICAL RAY-GRID INTERSECTION CODE   //
    ///////////////////////////////////////////
    int foundVertWallHit = 0;
    float vertWallHitX = 0;
    float vertWallHitY = 0;

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

    float nextVertTouchX = xintercept;
    float nextVertTouchY = yintercept;

    // Increment xstep and ystep until we find a wall
    while (nextVertTouchX >= 0 && nextVertTouchX <= g_tool.xa && nextVertTouchY >= 0 && nextVertTouchY <= g_tool.ya) {
        if (is_wall(nextVertTouchX - (g_map.left ? 1 : 0), nextVertTouchY)) {
            foundVertWallHit = 1;
            vertWallHitX = nextVertTouchX;
            vertWallHitY = nextVertTouchY;
            return;
        } else {
            nextVertTouchX += xstep;
            nextVertTouchY += ystep;
        }
    }
}