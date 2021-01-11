/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_of_view.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 11:16:16 by mmarzouk          #+#    #+#             */
/*   Updated: 2020/12/22 20:35:40 by mmarzouk         ###   ########.fr       */
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
	hhd = (casth())
		? distance(g_map.ppx, g_map.ppy, g_map.hwx, g_map.hwy)
		: MAXFLOAT;
	vhd = (castv())
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

int		casth(void)
{
	float xintercept;
	float yintercept;
	float xstep;
	float ystep;
	float nhtx;
	float nhty;

	yintercept = floor(g_map.ppy / TS) * TS;
	yintercept += g_map.down ? TS : 0;
	xintercept = g_map.ppx + (yintercept - g_map.ppy) / tan(g_map.rayd);
	ystep = TS;
	ystep *= g_map.up ? -1 : 1;
	xstep = TS / tan(g_map.rayd);
	xstep *= (g_map.left && xstep > 0) ? -1 : 1;
	xstep *= (g_map.right && xstep < 0) ? -1 : 1;
	nhtx = xintercept;
	nhty = yintercept;
	while (nhtx > 0 && nhtx < g_tool.cols * TS
		&& nhty > 0 && nhty < g_tool.rows * TS)
	{
		if (is_wall(nhtx, nhty - (g_map.up ? 1 : 0)))
		{
			g_map.hwx = nhtx;
			g_map.hwy = nhty;
			return (1);
		}
		else
		{
			nhtx += xstep;
			nhty += ystep;
		}
	}
	return (0);
}

int		castv(void)
{
	float xintercept;
	float yintercept;
	float xstep;
	float ystep;
	float nvtx;
	float nvty;

	xintercept = floor(g_map.ppx / TS) * TS;
	xintercept += g_map.right ? TS : 0;
	yintercept = g_map.ppy + (xintercept - g_map.ppx) * tan(g_map.rayd);
	xstep = g_map.left ? -1 * TS : TS;
	ystep = TS * tan(g_map.rayd);
	ystep *= (g_map.up && ystep > 0) ? -1 : 1;
	ystep *= (g_map.down && ystep < 0) ? -1 : 1;
	nvtx = xintercept;
	nvty = yintercept;
	while (nvtx >= 0 && nvtx <= g_tool.cols * TS &&
		nvty >= 0 && nvty <= g_tool.rows * TS)
	{
		if (is_wall(nvtx - (g_map.left ? 1 : 0), nvty))
		{
			g_map.vwx = nvtx;
			g_map.vwy = nvty;
			return (1);
		}
		else
		{
			nvtx += xstep;
			nvty += ystep;
		}
	}
	return (0);
}
