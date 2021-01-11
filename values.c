/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 08:27:16 by mmarzouk          #+#    #+#             */
/*   Updated: 2020/12/23 18:37:26 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	wall(void)
{
	int x;
	int y;

	x = g_map.nppx / TS;
	y = g_map.nppy / TS;
	if (!ft_strchr("1 2", g_map.map[y][x]))
	{
		x = g_map.ppx / TS;
		y = g_map.nppy / TS;
		if (!ft_strchr("1 2", g_map.map[y][x]))
		{
			x = g_map.nppx / TS;
			y = g_map.ppy / TS;
			if (!ft_strchr("1 2", g_map.map[y][x]))
			{
				g_map.ppx = g_map.nppx;
				g_map.ppy = g_map.nppy;
			}
		}
	}
}

int		is_wall(float x, float y)
{
	int a;
	int b;

	a = x / TS;
	b = y / TS;
	if (a >= g_tool.cols || b >= g_tool.rows)
		return (1);
	if (g_map.map[b][a] != '1')
	{
		return (0);
	}
	return (1);
}

void	render(void)
{
	init_values();
	floor_ceiling();
	updis();
	ft_fov();
	render_sprite();
	if(g_tool.save)
	{
		printf("djvbkv\n");
		make_a_bmp();
		exit(0);
	}
	mlx_put_image_to_window(g_ptr, g_win, g_image, 0, 0);
}

void	correcting_angle(void)
{
	if (g_map.pdrct > (2 * M_PI))
		g_map.pdrct -= 2 * M_PI;
	else if (g_map.pdrct < 0)
		g_map.pdrct += 2 * M_PI;
}

void	player_position(int *x, int *y)
{
	int i;
	int j;

	i = 0;
	while (g_map.map[i])
	{
		j = 0;
		while (g_map.map[i][j])
		{
			if (ft_strchr("NWSE", g_map.map[i][j]))
			{
				g_map.ppx = (j * TS) + (TS / 2);
				g_map.ppy = (i * TS) + (TS / 2);
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}
