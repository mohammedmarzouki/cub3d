/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:21:27 by mmarzouk          #+#    #+#             */
/*   Updated: 2020/11/03 12:39:11 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_free(char **d, int b)
{
	free(*d);
	*d = NULL;
	return (b);
}

static int	ft_retour(int b, char **s)
{
	if (b == 0)
		ft_free(s, 45);
	if (b > 1)
		return (1);
	else
		return (b);
}

static int	ft_shortcut(char **s, int fd)
{
	char	*tmp;
	char	*d;
	int		b;

	b = 1;
	if (!(d = malloc(sizeof(char) * 1000 + 1)))
		return (ft_free(&d, -1));
	while (b > 0 && !(ft_strch(*s, '\n')))
	{
		if ((b = read(fd, d, 1000)) < 0)
			return (ft_free(&d, b));
		d[b] = '\0';
		if (!*s && b > 0)
			*s = ft_strdu(d);
		else
		{
			tmp = *s;
			*s = ft_strjoi(*s, d);
			free(tmp);
		}
	}
	return (ft_free(&d, b));
}

static int	ft_read(int fd, char **s, char **line)
{
	char	*tmp;
	int		b;
	int		i;

	i = 0;
	if ((b = ft_shortcut(s, fd)) < 0)
		return (-1);
	while (*s && (*s)[i] != '\0' && (*s)[i] != '\n')
		i++;
	*line = ft_subst(*s, 0, i);
	tmp = *s;
	*s = ft_subst(*s, i + 1, ft_strle(*s));
	free(tmp);
	return (ft_retour(b, s));
}

int			get_next_line(int fd, char **line)
{
	static char *s;

	return (ft_read(fd, &s, line));
}
