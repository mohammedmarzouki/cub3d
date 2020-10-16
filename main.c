/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 07:27:16 by mmarzouk          #+#    #+#             */
/*   Updated: 2020/10/16 14:39:44 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
int try(int x,void *s)
{
	//w = 13
	//a = 0
	//s = 1
	//d = 2
	int i, j, k;
	
	if(x == 13 && (g_tool.y - 30) >= 0)
	{
		g_tool.y -= 30;
	}
	if (x == 0 && (g_tool.x - 30 ) >= 0)
	{
		g_tool.x -= 30;
	}
	if (x == 1 && (g_tool.y + 30 + 50) <= g_tool.ya)
	{
		g_tool.y += 30;
	}
	if (x == 2 && (g_tool.x + 30 + 50 ) <= g_tool.xa)
	{
		g_tool.x += 30;
	}
	ft_square(g_ptr,g_win);	
	return (0);
}
void looping()
{
	g_tool.xa = 800;
	g_tool.ya = 500;
	int i;
	int j;
	int k;
	init();
	g_ptr = mlx_init();
	g_win = mlx_new_window(g_ptr, g_tool.xa, g_tool.ya, "image");
	g_image = mlx_new_image(g_ptr,g_tool.xa,g_tool.ya);
	g_screen = (int *)mlx_get_data_addr(g_image,&i,&j,&k);
	mlx_hook(g_win,2,1,try,(void *)0);
	mlx_clear_window(g_ptr,g_win);
	ft_square(g_ptr,g_win);
	mlx_loop(g_ptr);
}
int main()
{
	ft_gnl();
	looping();
	printf("kdvbk\n");
	return(0);
}
