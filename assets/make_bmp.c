/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 09:25:57 by mmarzouk          #+#    #+#             */
/*   Updated: 2021/01/11 18:13:55 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

char	*make_header(t_header *values)
{
	char	*header;
	int		i;

	if (!(header = malloc(54)))
		ta_sir("allocation failed");
	ft_memset(header, 0, 54);
	values->width_in_bytes = (g_tool.xa * 24 + 31) / 32 * 4;
	values->image_size = values->width_in_bytes * g_tool.ya;
	ft_memcpy(header, "BM", 2);
	i = values->image_size + 54;
	ft_memcpy(header + 2, &i, 4);
	i = 54;
	ft_memcpy(header + 10, &i, 4);
	i = 40;
	ft_memcpy(header + 14, &i, 4);
	ft_memcpy(header + 18, &g_tool.xa, 4);
	ft_memcpy(header + 22, &g_tool.ya, 4);
	i = 1;
	ft_memcpy(header + 26, &i, 2);
	i = 24;
	ft_memcpy(header + 28, &i, 2);
	i = (((g_tool.xa * 24) + 31) / 32) * 4;
	ft_memcpy(header + 34, &i, 4);
	return (header);
}

int		*hex_to_rgb(int hex)
{
	int *rgb;

	rgb = malloc(3 * sizeof(int));
	rgb[0] = ((hex >> 16) & 0xFF);
	rgb[1] = ((hex >> 8) & 0xFF);
	rgb[2] = ((hex) & 0xFF);
	return (rgb);
}

char	*make_image(t_header *values)
{
	char	*buf;
	int		i;
	int		j;
	int		*colors;

	buf = malloc(values->image_size);
	i = g_tool.ya - 1;
	while (i > 0)
	{
		j = 0;
		while (j < g_tool.xa)
		{
			colors = hex_to_rgb(g_screen[((g_tool.ya - i)
			* g_tool.xa) + j]);
			buf[i * values->width_in_bytes + j * 3 + 2] = colors[0];
			buf[i * values->width_in_bytes + j * 3 + 1] = colors[1];
			buf[i * values->width_in_bytes + j * 3 + 0] = colors[2];
			free(colors);
			j++;
		}
		i--;
	}
	return (buf);
}

void	make_a_bmp(void)
{
	t_header	values;
	char		*header;
	char		*img;
	int			fd;

	header = make_header(&values);
	img = make_image(&values);
	fd = open("./screenshot.bmp", O_WRONLY | O_CREAT, 0x1A4);
	write(fd, header, 54);
	write(fd, img, values.image_size);
	free(header);
	free(img);
}
