/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 07:27:16 by mmarzouk          #+#    #+#             */
/*   Updated: 2020/12/13 13:26:54 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int		startswith(char c1, char c2, char *s)
{
	if (!c2)
	{
		if (s[0] == c1)
			return (1);
	}
	if (s[0] == c1 && s[1] == c2)
		return (1);
	return (0);
}

void	valid_line(char *s, int fd)
{
	if (!ft_strncmp(s, "NO", 2) && s[2] == ' ')
		chk_err(s, fd);
	else if (!ft_strncmp(s, "SO", 2) && s[2] == ' ')
		chk_err(s, fd);
	else if (!ft_strncmp(s, "WE", 2) && s[2] == ' ')
		chk_err(s, fd);
	else if (!ft_strncmp(s, "EA", 2) && s[2] == ' ')
		chk_err(s, fd);
	else if (!ft_strncmp(s, "S", 1) && s[1] == ' ')
		chk_err(s, fd);
	else if (!ft_strncmp(s, "R", 1) && s[1] == ' ')
		chk_resolution(s, fd);
	else if (!strncmp(s, "C", 1) && s[1] == ' ')
		chk_cf(s, fd);
	else if (startswith('F', 0, s) && s[1] == ' ')
		chk_cf(s, fd);
	else
		other(s, fd);
}

void	ft_gnl(int fd)
{
	int		i;
	char	*line;

	i = 1;
	while (i)
	{
		i = get_next_line(fd, &line);
		if (i < 0)
			ta_sir("file descriptor problem ");
		else
		{
			valid_line(line, fd);
			free(line);
		}
	}
	close(fd);
}

int				chk_file(char *f)
{
	int fd;

	if (!reversecheck(f,".cub"))
		ta_sir("file extention should be .cub");
	fd = open(f, O_RDONLY);
	if (fd < 0)
		ta_sir("file does not open");
	return (fd);
}
