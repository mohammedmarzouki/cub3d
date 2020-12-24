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
		if(((int)x % g_tool.ts == 0 || (int)y % g_tool.ts == 0 ||
		(int)x % g_tool.ts == g_tool.ts - 1 ||
		(int)y % g_tool.ts == g_tool.ts - 1 ) && is_wall(x,y))
		{
			//printf("%f-------%f\n",x,y);
			draw_walls(x,y);
			return;
		}
		g_screen[((int)(y* DIV) * g_tool.xa + (int)(x* DIV))] = violet;
		x += x_inc;
		y += y_inc;
	}
}
void ft_circle(int x,int y,int colour)
{
	int k;
	int a ;
	int b ;

	
	a = x - g_tool.ts;
	b = y - g_tool.ts;
	k = b;
	while(a < x + g_tool.ts)
	{
		b = k;
		while(b < y + g_tool.ts)
		{
			if(pow((a - x),2)+pow((b - y),2) <= pow(5,2))
				{
					g_screen[((int)(b* DIV) * g_tool.xa + (int)(a* DIV))] = violet;
				}
			b++;
		}
		a++;
	}
}