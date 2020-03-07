/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 07:27:16 by mmarzouk          #+#    #+#             */
/*   Updated: 2020/03/03 14:19:03 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
void ft_gnl(void)
{
    int fd;
    int i;
    char *line;
    char *s;
    
    fd = open("map.cub",O_RDONLY);
    s = ft_strdup("");
    i = 1;
    while((i = get_next_line(fd,&line)) >= 0)
    {
        printf("%s\n",line);
        free (line);
        if (i == 0)
            break;
    }
    
    
    close (fd);
}