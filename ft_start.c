/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 07:27:16 by mmarzouk          #+#    #+#             */
/*   Updated: 2020/03/03 14:03:03 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/*void ft_map(int *x,void *ptr,void *win)
{
    
}*/
void init(void)
{
    g_tool.x = 0;
    g_tool.y = 0;
}
void ft_square(void *ptr,void *win)
{
	int k;
	int a = 0;
	int b = 0;
	int f;

	mlx_clear_window(g_ptr,g_win);

	a = g_tool.x;
	b = g_tool.y;
	k = g_tool.y;
	g_tool.a = (g_tool.x + 50);
	g_tool.b = (g_tool.y + 50);
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