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
    corr = d * cos(g_map.rayd - g_map.pdrct);
    //printf("%f||%f||%f\n",d,x,y);

	
    pw = (TS / corr) * (g_tool.xa / 2)/tan(FOV/1.5);
    pw = pw > g_tool.ya ? g_tool.ya - 1 : pw;
	def_dir();
    a_line(g_tool.cntplyr,g_tool.ya/2 +(pw/2),g_tool.cntplyr,g_tool.ya/2 - (pw/2));
}
void def_dir(void)
{
	g_map.no = (g_map.up && g_map.hov)? 1 : 0;
	g_map.so = (g_map.down && g_map.hov)? 1 : 0;
	g_map.ea = (g_map.right && !g_map.hov)? 1 : 0;
	g_map.we = (g_map.left && !g_map.hov)? 1 : 0;
}
int find_color(void)
{
	if(g_map.no)
		return(0xFF00FF);
	if(g_map.so)
		return(0x00FF00);
	if(g_map.ea)
		return(0x0000FF);
	if(g_map.we)
		return(0xFFFFFF);
	return(0xFF0000);
}
void 	a_line(float x ,float y,float x1,float y1)
{
	float x_inc;
	float y_inc;
	float steps;
	float  b0;
    float  c0;
	int color = find_color();
	
	x_inc = x1 - x;
	y_inc = y1 - y;
	steps = fabs(x_inc) > fabs(y_inc) ? fabs(x_inc) : fabs(y_inc);
	x_inc = x_inc/steps;
	y_inc = y_inc/steps;
	b0 = x;
    c0 = y;
	while ((int)steps--)
	{
		g_screen[((int)(c0) * g_tool.xa + (int)(b0))] = color;
		b0 += x_inc;
		c0 += y_inc;
	}
}