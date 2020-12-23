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

void ft_fov(void)
{
    //float hold;

    g_tool.cntplyr = 0;
    hold = g_map.pdrct - (FOV / 2);
    while(hold < g_map.pdrct + (FOV / 2) && g_tool.cntplyr <= g_tool.xa)
    {
        draw_line(g_map.ppx,g_map.ppy,g_map.ppx+cos(hold)
        *INT16_MAX , g_map.ppy + sin(hold)*INT16_MAX);
        // printf("****%f****\n",g_map.pdrct + (FOV / 2));
        // printf("//// %f/////\n",hold);
        hold += FOV/g_tool.xa;
        g_tool.cntplyr++;
    }
}