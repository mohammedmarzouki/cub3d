/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawdim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:16:16 by mmarzouk          #+#    #+#             */
/*   Updated: 2021/01/11 17:35:16 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

float	distance(float x, float y, float x2, float y2)
{
	return (sqrt(pow((x - x2), 2) + pow((y - y2), 2)));
}

void	draw_walls(float x, float y)
{
	float	d;
	float	corr;

	d = distance(g_map.ppx, g_map.ppy, x, y);
	g_tool.wd[g_tool.wi] = d;
	g_tool.wi++;
	corr = d * cos(g_map.rayd - g_map.pdrct);
	g_map.wh = (TS / corr) * (g_tool.xa / 2) / tan(FOV / 1.5);
	def_dir();
	find_texture();
	put_texture(x, y);
}

void	def_dir(void)
{
	g_map.no = (g_map.up && g_map.hov) ? 1 : 0;
	g_map.so = (g_map.down && g_map.hov) ? 1 : 0;
	g_map.ea = (g_map.right && !g_map.hov) ? 1 : 0;
	g_map.we = (g_map.left && !g_map.hov) ? 1 : 0;
}

void	find_texture(void)
{
	if (g_map.no)
	{
		g_map.txt = g_xpm.no;
		g_map.txth = g_xpm.noh;
		g_map.txtw = g_xpm.now;
	}
	if (g_map.so)
	{
		g_map.txt = g_xpm.so;
		g_map.txth = g_xpm.soh;
		g_map.txtw = g_xpm.sow;
	}
	if (g_map.ea)
	{
		g_map.txt = g_xpm.ea;
		g_map.txth = g_xpm.eah;
		g_map.txtw = g_xpm.eaw;
	}
	if (g_map.we)
	{
		g_map.txt = g_xpm.we;
		g_map.txth = g_xpm.weh;
		g_map.txtw = g_xpm.wew;
	}
}

void	put_texture(float x, float y)
{
	float	inc;
	int		top;
	int		i;
	float	hold;

	top = (g_tool.ya / 2) - (g_map.wh / 2);
	inc = 0;
	i = 0;
	hold = TS / g_map.wh;
	while (++top < 0)
		inc += hold;
	if (g_map.hov)
	{
		x = (int)x % TS;
		while (i < g_map.wh && inc < (g_map.txth - 1) && (top < g_tool.ya))
		{
			g_screen[(top * g_tool.xa + g_tool.cntplyr)] =
				g_map.txt[(int)inc * g_map.txtw + (int)x];
			inc += hold;
			i++;
			top++;
		}
	}
	else
		vertic(y, top, hold);
}
