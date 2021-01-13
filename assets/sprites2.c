/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 08:57:42 by mmarzouk          #+#    #+#             */
/*   Updated: 2021/01/13 15:12:37 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void			draw_one_pixel(int x, int y, float color)
{
	if (y < g_tool.ya && y >= 0 && color != 0x000000)
	{
		g_screen[(y) * g_tool.xa + (x)] = color;
	}
}

void			draw_a_sprite(int x, float dis, float sp_height)
{
	int color;
	int i;
	int j;
	int y;

	i = x;
	while (i <= x + sp_height)
	{
		j = (g_tool.ya - sp_height) / 2;
		y = 0;
		if (i >= 0 && i < g_tool.xa && dis < g_tool.wd[i])
		{
			while (j < (g_tool.ya + sp_height) / 2 - 1)
			{
				color = g_xpm.s[(int)(y / sp_height * g_xpm.sh)
					* g_xpm.sw + (int)((i - x) / sp_height * g_xpm.sw)];
				draw_one_pixel(i, j, color);
				j++;
				y++;
			}
		}
		i++;
	}
}

static	void	swap_sprites(int i)
{
	t_sprite tmp;

	if (g_sp[i].d < g_sp[i + 1].d)
	{
		tmp = g_sp[i];
		g_sp[i] = g_sp[i + 1];
		g_sp[i + 1] = tmp;
	}
}

static	void	sort_sprites(void)
{
	int	f;
	int	l;

	f = 0;
	while (f < g_tool.sprites - 1)
	{
		l = 0;
		while (l < g_tool.sprites - 1 - f)
		{
			swap_sprites(l);
			l++;
		}
		f++;
	}
}

void			render_sprite(void)
{
	int			window_index;
	float		stripe_hight;
	float		angle;
	int			i;

	sort_sprites();
	i = 0;
	while (i < g_tool.sprites)
	{
		angle = atan2(g_sp[i].y - g_map.ppy, g_sp[i].x - g_map.ppx);
		if ((g_map.pdrct - FOV / 2) - angle > M_PI)
			angle = angle + 2 * M_PI;
		if (angle - (g_map.pdrct - FOV / 2) > M_PI)
			angle = angle - 2 * M_PI;
		stripe_hight = (TS / g_sp[i].d) * (g_tool.xa / 2) / tan(FOV / 1.5);
		window_index = (angle - (g_map.pdrct - FOV / 2)) /
			(FOV / g_tool.xa) - (stripe_hight / 2);
		draw_a_sprite(window_index, g_sp[i].d, stripe_hight);
		i++;
	}
}
