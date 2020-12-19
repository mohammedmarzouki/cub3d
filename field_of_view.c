/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_of_view.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 11:16:16 by mmarzouk          #+#    #+#             */
/*   Updated: 2020/12/18 20:13:03 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void ft_fov(void)
{
    float hold;
    int i = 0;
    
    hold = g_map.pdrct - FOV / 2;
    while(hold < g_map.pdrct + FOV / 2)
    {
        draw_line(g_map.ppx,g_map.ppy,g_map.ppx+cos(hold)*2550 , g_map.ppy + sin(hold)*2550);
        
        hold += FOV/g_tool.xa;
    }
}