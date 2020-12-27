/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:16:16 by mmarzouk          #+#    #+#             */
/*   Updated: 2020/12/24 11:18:42 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
float distance(float x,float y,float x2,float y2)
{
    return(sqrt(pow((x - x2),2) + pow((y - y2),2)));
}
void draw_walls(float x,float y)
{
    float d;
    float corr;
    float pw;

    d = distance(g_map.ppx,g_map.ppy,x,y);
    corr = d * cos(hold - g_map.pdrct);
    //printf("%f||%f||%f\n",d,x,y);

	
    pw = (TS / corr) * (g_tool.xa / 2)/tan(FOV/2);
    pw = pw > g_tool.ya ? g_tool.ya : pw;
    a_line(g_tool.cntplyr,g_tool.ya/2 +(pw/2),g_tool.cntplyr,g_tool.ya/2 - (pw/2));
}

void 	a_line(int x ,int y,int x1,int y1)
{
	float x_inc;
	float y_inc;
	float steps;
	float  b0;
    float  c0;
	
	x_inc = x1 - x;
	y_inc = y1 - y;
	steps = fabs(x_inc) > fabs(y_inc) ? fabs(x_inc) : fabs(y_inc);
	x_inc = x_inc/steps;
	y_inc = y_inc/steps;
	b0 = x;
    c0 = y;
	while ((int)steps--)
	{
		g_screen[((int)c0 * g_tool.xa + (int)b0)] = violet;
		b0 += x_inc;
		c0 += y_inc;
	}
}