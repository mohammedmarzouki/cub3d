/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 07:27:16 by mmarzouk          #+#    #+#             */
/*   Updated: 2020/12/07 18:52:46 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/*void ft_map(int *x,void *ptr,void *win)
{
    
}*/
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
void ft_square(void *ptr,void *win)
{
	int k;
	int a = 0;
	int b = 0;
	int f;

	

	a = g_tool.x;//the first point in x range
	b = g_tool.y;//the first point in y range
	k = g_tool.y;//k to reset the value
	g_tool.a = (g_tool.x + 50);//last point in the square
	g_tool.b = (g_tool.y + 50);//last point in the square
	while(a < g_tool.a)
	{
		b = k;
		while(b < g_tool.b)
		{
			f = (b * g_tool.xa + a);
			g_screen[f] = 0xFFBBAA;
			//mlx_pixel_put(g_ptr, g_win, a, b, 0xFFBBAA);
			b++;
		}
		a++;
	}
	mlx_put_image_to_window(g_ptr, g_win, g_image, 0 ,0 );
//	mlx_clear_window(g_ptr, g_win);
	g_image = mlx_new_image(g_ptr,g_tool.xa,g_tool.ya);
	g_screen = (int *)mlx_get_data_addr(g_image,&b,&a,&k);
}

void ft_circle(void *ptr,void *win)
{
	int k;
	int a ;
	int b ;
	int f;
	int r = 50;

	

	a = 0;
	b = k = 0;
	g_tool.a = (g_tool.x + 50);
	g_tool.b = (g_tool.y + 50);
	while(a < g_tool.xa)
	{
		b = k;
		while(b < g_tool.ya)
		{
			if(pow((a-g_tool.x),2)+pow((b-g_tool.y),2) <= pow(r,2))
				{
					f = (b * g_tool.xa + a);//index= current y pixel times* the last x pixel plus+ the current x pixel
					g_screen[f] = 0xFFBBAA;
				//mlx_pixel_put(g_ptr, g_win, a, b, 0xFFBBAA);
				}
			b++;
		}
		a++;
	}
	mlx_put_image_to_window(g_ptr, g_win, g_image, 0 ,0 );
//	mlx_clear_window(g_ptr, g_win);
	g_image = mlx_new_image(g_ptr,g_tool.xa,g_tool.ya);
	g_screen = (int *)mlx_get_data_addr(g_image,&b,&a,&k);
}