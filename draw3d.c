/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:16:16 by mmarzouk          #+#    #+#             */
/*   Updated: 2020/12/31 10:10:46 by mmarzouk         ###   ########.fr       */
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

    d = distance(g_map.ppx,g_map.ppy,x,y);
    corr = d * cos(g_map.rayd - g_map.pdrct);
    //printf("%f||%f||%f\n",d,x,y);
    g_map.wh = (TS / corr) * (g_tool.xa / 2)/tan(FOV/1.5);
    // g_map.wh = g_map.wh > g_tool.ya ? g_tool.ya - 1 : g_map.wh;
	def_dir();
	find_texture();
	put_texture(x,y);
    // a_line(g_tool.cntplyr,g_tool.ya/2 +(g_map.wh/2),g_tool.cntplyr,g_tool.ya/2 - (g_map.wh/2));
}
void def_dir(void)
{
	g_map.no = (g_map.up && g_map.hov)? 1 : 0;
	g_map.so = (g_map.down && g_map.hov)? 1 : 0;
	g_map.ea = (g_map.right && !g_map.hov)? 1 : 0;
	g_map.we = (g_map.left && !g_map.hov)? 1 : 0;
}
void find_texture(void)
{
	if(g_map.no)
	{
		g_map.txt = g_xpm.no;
		g_map.txth = g_xpm.noh;
		g_map.txtw = g_xpm.now;
	}
	if(g_map.so)
	{
		g_map.txt = g_xpm.so;
		g_map.txth = g_xpm.soh;
		g_map.txtw = g_xpm.sow;
	}
	if(g_map.ea)
	{
		g_map.txt = g_xpm.ea;
		g_map.txth = g_xpm.eah;
		g_map.txtw = g_xpm.eaw;
	}
	if(g_map.we)
	{
		g_map.txt = g_xpm.we;
		g_map.txth = g_xpm.weh;
		g_map.txtw = g_xpm.wew;
	}
}
void 	a_line(float x ,float y,float x1,float y1)
{
	float x_inc;
	float y_inc;
	float steps;
	float  b0;
    float  c0;
	// int color = find_color();
	
	x_inc = x1 - x;
	y_inc = y1 - y;
	steps = fabs(x_inc) > fabs(y_inc) ? fabs(x_inc) : fabs(y_inc);
	x_inc = x_inc/steps;
	y_inc = y_inc/steps;
	b0 = x;
    c0 = y;
	while ((int)steps--)
	{
		// printf("%f||||%f\n",b0,c0);
		//put_texture((int)b0,(int)c0);
		g_screen[(int)c0 * g_tool.xa +(int)(b0)] = 0X00FF00;
		b0 += x_inc;
		c0 += y_inc;
	}
}

void put_texture(float x,float y)
{
	float inc;
	int top;
	int i;
	float hold;


	top =  (g_tool.ya / 2) - (g_map.wh / 2);
	inc = 0;
	i = 0;
	hold = TS / g_map.wh;
	while(++top < 0)
		inc += hold;
	if (g_map.hov)
	{
		x = (int)x % TS;
		while (i < g_map.wh && inc < (g_map.txth - 1)  && (top < g_tool.ya))
		{
			g_screen[(top * g_tool.xa +g_tool.cntplyr)] = g_map.txt[(int)inc * g_map.txtw + (int)x];
			inc += hold;
			i++;
			top++;
		}
		
	}
	else
	{
		y = (int)y % TS;
		while (i < g_map.wh && inc < (g_map.txth - 1)  && (top < g_tool.ya))
		{
			g_screen[(top * g_tool.xa +g_tool.cntplyr)] = g_map.txt[(int)inc * g_map.txtw + (int)y];
			inc += hold;
			i++;
			top++;
		}
		
	}
	

	// wt = (g_tool.ya/2) - (g_map.wh/2);

	// xx = x % TS;
	// xt = xx * g_map.txtw / TS;
	// xx = (int)(g_map.wx  * g_map.txtw) / TS % g_map.txtw;
	// dft = wt + g_map.wh /2 - g_tool.ya/2;
	// //yt = y * g_map.txth / (int)g_map.wh;
	// yy = dft * g_map.txth/g_map.wh;
	// //  printf("%d||%d||%d||%d\n",yt ,(yt * g_map.txtw + xt),xt,(int)g_map.wh);
	// //  if( xt < 64)
	// // {
	// 	g_screen[( y * g_tool.xa + x)] = g_map.txt[(yy * g_map.txtw + xx)];
		// printf("jdfkkjsd\n");
	// }
	 	

}

// PULL REQUEST