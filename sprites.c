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

void    countsprites(void)
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
void    init_sprites(void)
{
    
}
t_sprite    *spalloc(void)
{
    t_sprite *sp;

    sp = malloc(sizeof(t_sprite) * g_tool.sprites);
    return(sp);
}