/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_handle1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 07:27:16 by mmarzouk          #+#    #+#             */
/*   Updated: 2020/11/29 12:04:06 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int doublecount(char **s)
{
    int i;

    i = 0;
    if (s)
    {
        while (s[i])
            i++;
    }
    return(i);
}
int alldigs(char *s,int len)
{
    int i;

    i = 0;
    while (i < len && s)
    {
        if(!ft_isdigit(s[i]))
            return(0);
        i++;
    }
    return(1);
}
void	chk_err(char *s, int fd)
{
	char	**str;
	void	*xpm_ptr;
	int		h[3];
	int		res[2];

	str = ft_split(s, ' ');
    printf("%s\n",str[1]);
	xpm_ptr = mlx_xpm_file_to_image(g_ptr, str[1], &res[0], &res[1]);
	if (xpm_ptr == NULL)
	{
        ft_putstr_fd(s,1); 
        close(fd);
		ta_sir("wrong xpm file");
	}
	if (ft_memcmp(str[0], "NO", 2) == 0)
		g_xpm.no = (int*)mlx_get_data_addr(xpm_ptr, &h[0], &h[1], &h[2]);
	else if (ft_memcmp(str[0], "EA", 2) == 0)
		g_xpm.ea = (int*)mlx_get_data_addr(xpm_ptr, &h[0], &h[1], &h[2]);
	else if (ft_memcmp(str[0], "SO", 2) == 0)
		g_xpm.so = (int*)mlx_get_data_addr(xpm_ptr, &h[0], &h[1], &h[2]);
	else if (ft_memcmp(str[0], "WE", 2) == 0)
		g_xpm.we = (int*)mlx_get_data_addr(xpm_ptr, &h[0], &h[1], &h[2]);
	else if (ft_memcmp(str[0], "S", 1) == 0)
		g_xpm.s = (int*)mlx_get_data_addr(xpm_ptr, &h[0], &h[1], &h[2]);
	
}
void    chk_resolution(char *s,int fd)
{
    int i;
    int j;
    char **str;
    
    i = 0;
    str = ft_split(s, ' ');
    if (doublecount(str) == 3)
    {
        if(!(alldigs(str[1],strlen(str[1])) && alldigs(str[2],strlen(str[2]))))
            ta_sir("wrong resolution input");
        g_tool.ya = ft_atoi(str[1]);
        g_tool.xa = ft_atoi(str[2]);
        return;
    }
    ta_sir("wrong resolution input"); 
}