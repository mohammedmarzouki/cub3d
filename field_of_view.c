/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_of_view.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 11:16:16 by mmarzouk          #+#    #+#             */
/*   Updated: 2020/12/22 19:54:00 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void ft_fov(void)
{
    //float hold;

    g_tool.cntplyr = 0;
    hold = g_map.pdrct - FOV / 2;
    while(hold < g_map.pdrct + FOV / 2)
    {
        draw_line(g_map.ppx,g_map.ppy,g_map.ppx+cos(hold)
        *INT16_MAX , g_map.ppy + sin(hold)*INT16_MAX);
        printf("hold ---- %f\n",hold);
        hold += FOV/g_tool.xa;
        g_tool.cntplyr++;
    }
}