/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:13:21 by mmarzouk          #+#    #+#             */
/*   Updated: 2021/01/13 15:10:07 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H
# include "/usr/local/include/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "global.h"
# include "typedef.h"

# define W		13
# define S		1
# define A		0
# define D		2
# define STP	20
# define FOV	1.0471975512
# define DIV	0
# define TS		64

void			ft_square(void *ptr, void *win);
void			init(void);
void			ft_gnl(int fd);
int				checking(char *cub);
void			ft_circle(int a, int b, int colour);
int				end(int x, void *s);
void			ta_sir(char *s);
void			chk_err(char *s);
void			chk_cf(char *s);
void			chk_resolution(char *s);
int				countchars(char *s, char c);
int				alldigs(char *s, int len);
int				doublecount(char **s);
void			doublefree(char **ptr);
void			affect_coulour(char **colour, char c);
int				reversecheck(char *s, char *str);
void			other(char *s);
int				alldone(void);
void			affect_xpm(void	*xpm_ptr);
int				itismap(char *s);
int				allspaces(char *s);
void			save_map(char *s);
void			handling_errors(void);
void			handling_map(int i);
void			resizing_map(int i, int big_len);
void			check_map_errors(int max_x, int max_y);
int				trgb(int t, int r, int g, int b);
void			square(int x, int y, int lenght, int colour);
void			draw_line(float x, float y, float x1, float y1);
void			init_values(void);
void			render(void);
void			player_position(int *x, int *y);
void			wall(void);
void			correcting_angle(void);
int				is_wall(float x, float y);
void			ft_fov(void);
void			draw_walls(float x, float y);
float			distance(float x, float y, float x2, float y2);
void			raycast(void);
void			ray_direction(void);
int				casth(float xintercept, float yintercept,
					float xstep, float ystep);
int				castv(float xintercept, float yintercept,
					float xstep, float ystep);
void			def_dir(void);
void			find_texture(void);
void			ptr_wh(int x, int y);
void			put_texture(float x, float y);
void			floor_ceiling(void);
void			get_center(float *x, float *y);
void			countsprites(void);
void			init_sprites(void);
void			affsp(float x, float y);
void			spalloc(void);
void			updis(void);
void			draw_one_pixel(int y, int x, float color);
void			draw_a_sprite(int x, float dis, float sp_height);
void			render_sprite(void);
int				chk_file(char *f);
void			save_flag(char *s);
int				same(char *s1, char *s2);
void			make_a_bmp(void);
int				ft_atoi(const char *str);
int				ft_isdigit(int a);
int				ft_memcmp(const void *buf1, const void *buf2, size_t count);
void			*ft_memcpy(void *to, const void *from, size_t n);
void			*ft_memset(void *buf, int x, size_t count);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
char			**ft_split(char const *s, char c);
char			*ft_strchr(const char *str, int c);
char			*ft_strdup(const char *str);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlen(const char *str);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
size_t			ft_strle(const char *str);
char			*ft_strdu(const char *str);
char			*ft_strjoi(char const *s1, char const *s2);
char			*ft_strch(const char *str, int c);
char			*ft_subst(char const *s, unsigned int start, size_t len);
int				get_next_line(int fd, char **line);
void			vertic(float y, int top, float hold, float inc);
void			map_errors_again(int max_x, int max_y);
void			x_bouton(int x);
#endif
