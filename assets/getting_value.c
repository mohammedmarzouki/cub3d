/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getting_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 07:27:16 by mmarzouk          #+#    #+#             */
/*   Updated: 2021/01/13 14:11:40 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	affect_coulour(char **colour, char c)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (!alldigs(colour[i], ft_strlen(colour[i])))
			ta_sir("wrong RGB value, there should be only numbers");
		i++;
	}
	if (c == 'C' && g_tool.cflag == 0)
	{
		g_tool.cflag = 1;
		g_tool.cr = ft_atoi(colour[0]);
		g_tool.cg = ft_atoi(colour[1]);
		g_tool.cb = ft_atoi(colour[2]);
	}
	else if (c == 'F' && g_tool.fflag == 0)
	{
		g_tool.fflag = 1;
		g_tool.fr = ft_atoi(colour[0]);
		g_tool.fg = ft_atoi(colour[1]);
		g_tool.fb = ft_atoi(colour[2]);
	}
	else
		ta_sir("colour already taken");
}

void	ptr_wh(int x, int y)
{
	if (!ft_memcmp(g_tool.vars.hold[0], "NO", 2))
	{
		g_xpm.now = x;
		g_xpm.noh = y;
	}
	else if (!ft_memcmp(g_tool.vars.hold[0], "EA", 2))
	{
		g_xpm.eaw = x;
		g_xpm.eah = y;
	}
	else if (!ft_memcmp(g_tool.vars.hold[0], "SO", 2))
	{
		g_xpm.sow = x;
		g_xpm.soh = y;
	}
	else if (!ft_memcmp(g_tool.vars.hold[0], "WE", 2))
	{
		g_xpm.wew = x;
		g_xpm.weh = y;
	}
	else if (!ft_memcmp(g_tool.vars.hold[0], "S", 1))
	{
		g_xpm.sw = x;
		g_xpm.sh = y;
	}
}

void	save_flag(char *s)
{
	if (!same(s, "--save"))
		ta_sir("did you mean '--save' ?");
	g_tool.save = 1;
}

int		same(char *s1, char *s2)
{
	if (!s1 && !s2)
		return (1);
	if (!s1 || !s2)
		return (0);
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	while (*s1)
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	return (1);
}
