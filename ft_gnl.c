/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 07:27:16 by mmarzouk          #+#    #+#             */
/*   Updated: 2020/10/16 11:31:11 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"


void ft_gnl(void)
{
    int fd;
    int i;
    char *line;
    char **art;
    char ***arter;
    
    fd = open("map.cub",O_RDONLY);
    i = get_next_line(fd,&line);
    if (i == -1)
        return;
    art = ft_split(line,'\n');
    if (checking(art))
        printf("valid\n");
    else
        printf("not valid\n");
    i = 0;
    while (art[i])
    {
        printf("%s |%d|\n",art[i],i);
        i++;
    }
    free (line);
    close (fd);
}