/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 15:17:40 by mmarzouk          #+#    #+#             */
/*   Updated: 2021/01/04 15:17:48 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	countsprites(void)
{
	int i;

	i = 0;
	while (g_tool.vars.carrier[i])
	{
		if (g_tool.vars.carrier[i] == '2')
			g_tool.sprites++;
		i++;
	}
}

void	updis(void)
{
	int i;

	i = 0;
	while (i < g_tool.sprites)
	{
		g_sp[i].d = distance(g_map.ppx, g_map.ppy, g_sp[i].x, g_sp[i].y);
		i++;
	}
}

void	affsp(float x, float y)
{
	static int i = 0;

	x *= TS;
	y *= TS;
	get_center(&x, &y);
	g_sp[i].x = x;
	g_sp[i].y = y;
	i += 1;
}

void	init_sprites(void)
{
	int x;
	int y;

	y = 0;
	if (!g_sp)
		return ;
	while (g_map.map[y])
	{
		x = 0;
		while (g_map.map[y][x])
		{
			if (g_map.map[y][x] == '2')
				affsp(x, y);
			x++;
		}
		y++;
	}
}

void	spalloc(void)
{
	g_sp = (t_sprite *)malloc(sizeof(t_sprite) * g_tool.sprites);
	g_tool.wd = (float *)malloc(sizeof(float) * g_tool.xa);
	g_tool.wi = 0;
	if (!g_sp || !g_tool.wd)
		ta_sir("allocation failed");
}
