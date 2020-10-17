/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:21:27 by mmarzouk          #+#    #+#             */
/*   Updated: 2020/10/16 10:15:40 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_read(int fd, char **s)
{
	char	*tmp;
	char 	*b;
	int		i;

	i = 1;
	if (!(b = malloc(sizeof(char) * 1001)))
		return(-1);
	*s = ft_strdu("");
	while(i > 0)
	{
		i = read(fd,b,1000);
		tmp = *s;
		*s = ft_strjoi(*s,b);
		free (tmp);
		
		tmp = b;
		b = ft_strdu("");
		free(tmp);
		tmp = NULL;
	}
	
	return(1);
}

int			get_next_line(int fd, char **s)
{
	return (ft_read(fd, s));
}
