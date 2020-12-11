/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 07:27:16 by mmarzouk          #+#    #+#             */
/*   Updated: 2020/12/10 11:07:12 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
void ta_sir(char *s)
{
	write(1,"Error \n",7);
	ft_putstr_fd(s,1);
	write(1,"\n",1);
	
	exit(0);
}

int end(int x,void *s)
{
	mlx_destroy_window(g_ptr,g_win);
	exit(0);
}

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
	if (x == 53)
		end(x,s);
	ft_circle(g_ptr,g_win);	
	return (0);
}
void looping()
{
	int i;
	int j;
	int k;

	g_tool.xa = 500;
	g_tool.ya = 800;
	
	g_win = mlx_new_window(g_ptr, g_tool.xa, g_tool.ya, "image");
	g_image = mlx_new_image(g_ptr,g_tool.xa,g_tool.ya);
	g_screen = (int *)mlx_get_data_addr(g_image,&i,&j,&k);
	mlx_hook(g_win,2,1,try,NULL);
	mlx_hook(g_win,17,0,end,NULL);
	mlx_clear_window(g_ptr,g_win);
	ft_circle(g_ptr,g_win);
	mlx_loop(g_ptr);
}
int main()
{
	//initialize
	init();
	ft_gnl();
	handling_errors();
	printf("\n%d\n",g_tool.xa);
	//looping();
	return(0);
}
