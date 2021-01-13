/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_of_view.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 11:16:16 by mmarzouk          #+#    #+#             */
/*   Updated: 2021/01/13 14:33:50 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_fov(void)
{
	float check;

	g_tool.cntplyr = 0;
	g_map.rayd = g_map.pdrct - (FOV / 2);
	check = g_map.rayd;
	while (check < g_map.pdrct + (FOV / 2) && g_tool.cntplyr < g_tool.xa)
	{
		raycast();
		draw_walls(g_map.wx, g_map.wy);
		g_map.rayd += FOV / g_tool.xa;
		check += FOV / g_tool.xa;
		if (g_map.rayd > (2 * M_PI))
			g_map.rayd -= 2 * M_PI;
		else if (g_map.rayd < 0)
			g_map.rayd += 2 * M_PI;
		g_tool.cntplyr++;
	}
	g_tool.wi = 0;
}

void	raycast(void)
{
	float hhd;
	float vhd;

	ray_direction();
	hhd = (casth(0.0, 0.0, 0.0, 0.0))
		? distance(g_map.ppx, g_map.ppy, g_map.hwx, g_map.hwy)
		: MAXFLOAT;
	vhd = (castv(0.0, 0.0, 0.0, 0.0))
		? distance(g_map.ppx, g_map.ppy, g_map.vwx, g_map.vwy)
		: MAXFLOAT;
	g_map.wx = (hhd < vhd) ? g_map.hwx : g_map.vwx;
	g_map.wy = (hhd < vhd) ? g_map.hwy : g_map.vwy;
	g_map.dis = (hhd < vhd) ? hhd : vhd;
	g_map.hov = (hhd < vhd) ? 1 : 0;
}

void	ray_direction(void)
{
	g_map.down = (g_map.rayd > 0 && g_map.rayd < M_PI) ? 1 : 0;
	g_map.up = (g_map.down) ? 0 : 1;
	g_map.right = (g_map.rayd < M_PI / 2 || g_map.rayd > 3 * M_PI / 2) ? 1 : 0;
	g_map.left = (g_map.right) ? 0 : 1;
}

int		casth(float xintercept, float yintercept, float xstep, float ystep)
{
	yintercept = floor(g_map.ppy / TS) * TS;
	yintercept += g_map.down ? TS : 0;
	xintercept = g_map.ppx + (yintercept - g_map.ppy) / tan(g_map.rayd);
	ystep = TS;
	ystep *= g_map.up ? -1 : 1;
	xstep = TS / tan(g_map.rayd);
	xstep *= (g_map.left && xstep > 0) ? -1 : 1;
	xstep *= (g_map.right && xstep < 0) ? -1 : 1;
	while (xintercept > 0 && xintercept < g_tool.cols * TS
		&& yintercept > 0 && yintercept < g_tool.rows * TS)
	{
		if (is_wall(xintercept, yintercept - (g_map.up ? 1 : 0)))
		{
			g_map.hwx = xintercept;
			g_map.hwy = yintercept;
			return (1);
		}
		else
		{
			xintercept += xstep;
			yintercept += ystep;
		}
	}
	return (0);
}

int		castv(float xintercept, float yintercept, float xstep, float ystep)
{
	xintercept = floor(g_map.ppx / TS) * TS;
	xintercept += g_map.right ? TS : 0;
	yintercept = g_map.ppy + (xintercept - g_map.ppx) * tan(g_map.rayd);
	xstep = g_map.left ? -1 * TS : TS;
	ystep = TS * tan(g_map.rayd);
	ystep *= (g_map.up && ystep > 0) ? -1 : 1;
	ystep *= (g_map.down && ystep < 0) ? -1 : 1;
	while (xintercept >= 0 && xintercept <= g_tool.cols * TS &&
		yintercept >= 0 && yintercept <= g_tool.rows * TS)
	{
		if (is_wall(xintercept - (g_map.left ? 1 : 0), yintercept))
		{
			g_map.vwx = xintercept;
			g_map.vwy = yintercept;
			return (1);
		}
		else
		{
			xintercept += xstep;
			yintercept += ystep;
		}
	}
	return (0);
}
