/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_handle1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 07:27:16 by mmarzouk          #+#    #+#             */
/*   Updated: 2020/12/02 16:49:32 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"



void chk_cf(char *s, int fd)
{
    g_tool.vars.hold = ft_split(s,' ');
    if (doublecount(g_tool.vars.hold) == 2)
    {
        if (countchars(g_tool.vars.hold[1],',') == 2)
        {
            g_tool.vars.colour = ft_split(g_tool.vars.hold[1],',');
            if(doublecount(g_tool.vars.colour) == 3)
                affect_coulour(g_tool.vars.colour,s[0],g_tool.vars.hold);
            else
                ta_sir("the RGB is in a wrong format");
        }
        else
            ta_sir("RGB in wrong format");
    }
    else
        ta_sir("colour format is wrong");
    doublefree(g_tool.vars.colour);
    doublefree(g_tool.vars.hold);
}

void	chk_err(char *s, int fd)
{
	void	*xpm_ptr;
	int		h[3];

	g_tool.vars.hold = ft_split(s, ' ');
    if (doublecount(g_tool.vars.hold) != 2 || !reversecheck(g_tool.vars.hold[1],".xpm"))
    {
        doublefree(g_tool.vars.hold);
        ta_sir("xpm file in wrong format");
    }
	xpm_ptr = mlx_xpm_file_to_image(g_ptr, g_tool.vars.hold[1], &h[0], &h[1]);
	if (xpm_ptr == NULL)
	{
        close(fd);
		ta_sir("wrong xpm file");
	}
	if (ft_memcmp(g_tool.vars.hold[0], "NO", 2) == 0)
		g_xpm.no = (int*)mlx_get_data_addr(xpm_ptr, &h[0], &h[1], &h[2]);
	else if (ft_memcmp(g_tool.vars.hold[0], "EA", 2) == 0)
		g_xpm.ea = (int*)mlx_get_data_addr(xpm_ptr, &h[0], &h[1], &h[2]);
	else if (ft_memcmp(g_tool.vars.hold[0], "SO", 2) == 0)
		g_xpm.so = (int*)mlx_get_data_addr(xpm_ptr, &h[0], &h[1], &h[2]);
	else if (ft_memcmp(g_tool.vars.hold[0], "WE", 2) == 0)
		g_xpm.we = (int*)mlx_get_data_addr(xpm_ptr, &h[0], &h[1], &h[2]);
	else if (ft_memcmp(g_tool.vars.hold[0], "S", 1) == 0)
		g_xpm.s = (int*)mlx_get_data_addr(xpm_ptr, &h[0], &h[1], &h[2]);
}

void    chk_resolution(char *s,int fd)
{
    int i;
    int j;
    char **str;
    
    i = 0;
    str = ft_split(s, ' ');
    if (doublecount(str) == 3)
    {
        if(!(alldigs(str[1],ft_strlen(str[1])) && alldigs(str[2],ft_strlen(str[2]))))
            ta_sir("wrong resolution input");
        g_tool.ya = ft_atoi(str[1]);
        g_tool.xa = ft_atoi(str[2]);
        return;
    }
    ta_sir("wrong resolution input"); 
}