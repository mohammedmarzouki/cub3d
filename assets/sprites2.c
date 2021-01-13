/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 08:57:42 by mmarzouk          #+#    #+#             */
/*   Updated: 2021/01/11 16:21:22 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void			draw_one_pixel(int y, int x, double color)
{
	if (y < g_tool.ya && y >= 0 && color != 0x000000)
	{
		g_screen[(y) * g_tool.xa + (x)] = color;
	}
}

void			draw_sprites(int x, float distance, float height)
{
	int i;
	int j;
	int y_offset;
	int color;

	i = x;
	while (i <= x + height)
	{
		j = (g_tool.ya - height) / 2;
		y_offset = 0;
		if (i >= 0 && i < g_tool.xa && distance < g_tool.wd[i])
		{
			while (j < (g_tool.ya + height) / 2 - 1)
			{
				color = g_xpm.s[(int)(y_offset / height * g_xpm.sh)
					* g_xpm.sw + (int)((i - x) / height * g_xpm.sw)];
				draw_one_pixel(j, i, color);
				j++;
				y_offset++;
			}
		}
		i++;
	}
}

static	void	swap(int i)
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
	int	i;
	int	j;

	i = 0;
	while (i < g_tool.sprites - 1)
	{
		j = 0;
		while (j < g_tool.sprites - 1 - i)
		{
			swap(j);
			j++;
		}
		i++;
	}
}

void			render_sprite(void)
{
	float		angle;
	float		sprite_height;
	int			column_index;
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
		sprite_height = (TS / g_sp[i].d) * (g_tool.xa / 2) / tan(FOV / 1.5);
		column_index = (angle - (g_map.pdrct - FOV / 2)) /
			(FOV / g_tool.xa) - (sprite_height / 2);
		draw_sprites(column_index, g_sp[i].d, sprite_height);
		i++;
	}
}
