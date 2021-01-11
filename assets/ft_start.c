/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 07:27:16 by mmarzouk          #+#    #+#             */
/*   Updated: 2020/12/24 11:02:25 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	init(void)
{
	g_ptr = mlx_init();
	g_tool.sprites = 0;
	g_tool.readingmap = 0;
	g_tool.cntplyr = 0;
	g_tool.save = 0;
	g_xpm.no = NULL;
	g_xpm.so = NULL;
	g_xpm.ea = NULL;
	g_xpm.we = NULL;
	g_xpm.s = NULL;
	g_tool.vars.carrier = ft_strdup("");
}

void	get_center(float *x, float *y)
{
	*x = floor(*x / TS) * TS + TS / 2;
	*y = floor(*y / TS) * TS + TS / 2;
}

void	init_values(void)
{
	int i;
	int j;

	player_position(&j, &i);
	if (g_map.map[i][j] == 'N')
		g_map.pdrct = 3 * M_PI / 2;
	else if (g_map.map[i][j] == 'S')
		g_map.pdrct = M_PI / 2;
	else if (g_map.map[i][j] == 'W')
		g_map.pdrct = M_PI;
	else if (g_map.map[i][j] == 'E')
		g_map.pdrct = 0;
}
