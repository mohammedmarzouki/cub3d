/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 07:27:16 by mmarzouk          #+#    #+#             */
/*   Updated: 2020/11/03 12:15:07 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

char *crop(char *s,int *i)
{

    *i = 0;
    if (s)
        while (s[(*i)])
        {
            if(s[(*i)] == '1')
            {
                while(s[(*i)] != '\n' && *i > 0)
                    (*i)--;
                return(ft_substr(s,*i,strlen(s))); 
            }
            (*i)++;
        }
    return (NULL);
}
void ft_gnl(void)
{
    int fd;
    int i;
    char *line;

    
    fd = open("map.cub",O_RDONLY);
    i = get_next_line(fd,&line);
    if (i == -1)
        return;
    //if (checking(line))
    printf("%s\n",line);
    //else
    //    printf("not valid\n");
    i = 0;
    free (line);
    close (fd);
}
    // while (art[i])
    // {
    //     printf("%s |%d|\n",art[i],i);
    //     i++;
    // }