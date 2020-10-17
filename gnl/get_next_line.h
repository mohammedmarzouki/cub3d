/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 14:27:32 by mmarzouk          #+#    #+#             */
/*   Updated: 2020/10/15 16:57:50 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

int			get_next_line(int fd, char **line);
size_t		ft_strle(const char *str);
char		*ft_strdu(const char *str);
char		*ft_strjoi(char const *s1, char const *s2);
char		*ft_subst(char const *s, unsigned int start, size_t len);
#endif
