/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 07:27:16 by mmarzouk          #+#    #+#             */
/*   Updated: 2020/12/23 18:30:41 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int		trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	floor_ceiling(void)
{
	int x;
	int y;
	int hold;
	int colour;

	y = 0;
	hold = g_tool.ya / 2;
	colour = trgb(0, g_tool.cr, g_tool.cg, g_tool.cb);
	while (y < g_tool.ya)
	{
		while (y < hold)
		{
			x = 0;
			while (x < g_tool.xa)
			{
				g_screen[(y * g_tool.xa + x)] = colour;
				x++;
			}
			y++;
		}
		colour = trgb(0, g_tool.fr, g_tool.fg, g_tool.fb);
		hold = g_tool.ya;
	}
}
