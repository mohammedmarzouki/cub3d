/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 07:27:16 by mmarzouk          #+#    #+#             */
/*   Updated: 2020/12/24 11:02:25 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void init(void)
{
	g_ptr = mlx_init();
    g_tool.x = 20;
    g_tool.y = 30;
	g_tool.sprites = 0;
	g_tool.readingmap = 0;
	g_tool.cntplyr = 0;
	g_xpm.no =  NULL;
	g_xpm.so =  NULL;
	g_xpm.ea =  NULL;
	g_xpm.we =  NULL;
	g_xpm.s =  NULL;
	g_tool.vars.carrier = ft_strdup("");
}
void 	draw_line(float x ,float y,float x1,float y1)
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
	//printf("%f---%f---%f\n",x_inc,steps,y_inc);
	// b0 = x;
    // c0 = y;
	while ((int)steps--)
	{
		// if(((int)x % TS == 0 || (int)y % TS == 0 ||
		// (int)x % TS == TS - 1 ||
		// (int)y % TS == TS - 1 ) && is_wall(x,y))
		// {
		// 	//printf("%f-------%f\n",x,y);
		// 	draw_walls(x,y);
		// 	return;
		// }
		g_screen[((int)(y* DIV) * g_tool.xa + (int)(x* DIV))] = 0x0000FF;
		x += x_inc;
		y += y_inc;
	}
}
void ft_circle(int x,int y,int colour)
{
	int k;
	int a ;
	int b ;

	
	a = x - TS;
	b = y - TS;
	k = b;
	while(a < x + TS)
	{
		b = k;
		while(b < y + TS)
		{
			if(pow((a - x),2)+pow((b - y),2) <= pow(20,2))
				{
					g_screen[((int)(b* DIV) * g_tool.xa + (int)(a* DIV))] = colour;
				}
			b++;
		}
		a++;
	}
}
void get_center( float *x, float *y)
{
	*x = floor(*x / TS) * TS + TS / 2;
	*y = floor(*y / TS) * TS + TS / 2;
}