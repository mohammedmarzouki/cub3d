/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 17:57:37 by mmarzouk          #+#    #+#             */
/*   Updated: 2020/10/15 16:58:05 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strle(const char *str)
{
	size_t i;

	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdu(const char *str)
{
	unsigned int	leng;
	unsigned int	i;
	char			*dup;

	leng = ft_strle((char *)str);
	dup = (char *)malloc((sizeof(char) * (leng + 1)));
	if (dup == 0)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = str[i];
	return (dup);
}

char	*ft_strjoi(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*s;

	if (s1 && s2)
		i = ft_strle((char *)s1);
	else
		return (0);
	j = ft_strle((char *)s2);
	if (!(s = (char *)malloc(sizeof(char) * (i + j + 1))))
		return (0);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		s[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		s[i++] = s2[j++];
	s[i] = '\0';
	return (s);
}
