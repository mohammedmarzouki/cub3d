/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_handle2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 11:16:16 by mmarzouk          #+#    #+#             */
/*   Updated: 2020/12/10 11:07:03 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void    printtwod(char **map)
{   
    int i;
    i = 0;
    while(map[i])
    {
        ft_putchar_fd('|',1);
        ft_putstr_fd(map[i],1);
        ft_putchar_fd('|',1);
        ft_putchar_fd('\n',1);
        i++;
    }
}
void    handling_errors(void)
{
    if (g_tool.xa > 2560 || g_tool.xa < 0)
        g_tool.xa = 2560;
    if (g_tool.ya > 1440 || g_tool.ya < 0)
        g_tool.ya = 1440;
    if (g_tool.cr > 255 || g_tool.cg > 255 || g_tool.cb > 255)
        ta_sir("ceiling color are not correct");
    if (g_tool.fr > 255 || g_tool.fg > 255 || g_tool.fb > 255)
        ta_sir("floor color are not correct");
    if(g_tool.readingmap)
        handling_map(0);
    else
        ta_sir("404 map not found");
}

void    handling_map(int i)
{
    int big_len;



    g_map.map = ft_split(g_tool.vars.carrier,'\n');
    //free carrier
    big_len = ft_strlen(g_map.map[i]);
    while(g_map.map[i])
    {
        if(big_len < ft_strlen(g_map.map[i]))
            big_len = ft_strlen(g_map.map[i]);
        i++;
    }
    resizing_map(0,big_len);
    printtwod(g_map.map);
    g_tool.cols = ft_strlen(g_map.map[0]);
    g_tool.rows = doublecount(g_map.map) ; 
    check_map_errors(g_tool.cols,g_tool.rows);
    if(!g_tool.cntplyr)
        ta_sir("there is no player in the map");
}
void check_map_errors(int max_x,int max_y)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while(x < max_x)
    {
        y = 0;

        while(y < max_y)
        {

            if(ft_strchr("02NSEW",g_map.map[y][x]) && 
            (x == 0 || y == 0 || x == max_x-1 || y == max_y-1))
                ta_sir("map is not closed !");
            else if(ft_strchr("02NSEW",g_map.map[y][x]) && 
            (g_map.map[y+1][x] == ' ' || g_map.map[y - 1][x] == ' '))
                ta_sir("please close the map");
            y++;
        }
        x++;
    }
    x = 0;
    y = 0;
    //printf("%d|||%d\n",x,y);
    while(y < max_y)
    {
        x = 0;
        while(x < max_x)
        {
            if(ft_strchr("02NSEW",g_map.map[y][x]) && 
            (x == 0 || y == 0 || x == max_x-1 || y == max_y-1))
                ta_sir("map is not closed !");
            else if(ft_strchr("02NSEW",g_map.map[y][x]) && 
            (g_map.map[y][x +1] == ' ' || g_map.map[y][x - 1] == ' '))
                ta_sir("please close the map");
            x++;
        }
        y++;
    }

}
void resizing_map(int i,int big_len)
{
    char *hold;
    char *carry;
    int j;
    
    while(g_map.map[i])
    {
        j = ft_strlen(g_map.map[i]);
        if (big_len > j)
        {
            j = big_len - j;
            hold = (char*)malloc(j + 1);
            hold[j] = '\0';
            hold = ft_memset(hold,' ',j);
            carry = g_map.map[i];
            g_map.map[i] = ft_strjoin(g_map.map[i],hold);
            free(hold);
            free(carry);
        }
        i++;
    }
}