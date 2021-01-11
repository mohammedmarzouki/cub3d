/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:13:21 by mmarzouk          #+#    #+#             */
/*   Updated: 2021/01/08 16:13:25 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H
# define CUBE_H
# define CUBE_H
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>


# define W		13
# define S		1
# define A		0
# define D		2
# define STP	20
# define FOV	1.0471975512
# define DIV	0
# define TS		64

void			*g_ptr;
void			*g_win;
void			*g_image;
int				*g_screen;

typedef struct	s_free
{
	char **hold;
	char **colour;
	char *carrier;
}				t_free;

typedef	struct	s_tool
{
	int			save;
	int			xa;
	int			ya;
	int			cr;
	int			cg;
	int			cb;
	int			fr;
	int			fg;
	int			fb;
	int			resflag;
	int			cflag;
	int			fflag;
	int			readingmap;
	int			cntplyr;
	int			rows;
	int			cols;
	int			sprites;
	float		*wd;
	int			wi;
	t_free		vars;
}				t_tool;

typedef struct	s_xpm
{
	int			*no;
	int			*so;
	int			*ea;
	int			*we;
	int			*s;
	int			now;
	int			noh;
	int			sow;
	int			soh;
	int			eaw;
	int			eah;
	int			wew;
	int			weh;
	int			sw;
	int			sh;
}				t_xpm;

typedef struct	s_sprite
{
	float		x;
	float		y;
	float		d;
	int			fov;
}				t_sprite;

typedef struct	s_map
{
	char		**map;
	int			*txt;
	int			txth;
	int			txtw;
	int			down;
	int			up;
	int			left;
	int			right;
	int			no;
	int			so;
	int			ea;
	int			we;
	char		hov;
	float		ppx;
	float		ppy;
	float		pdrct;
	float		nppx;
	float		nppy;
	float		rayd;
	float		wx;
	float		wy;
	float		dis;
	float		hwx;
	float		hwy;
	float		vwx;
	float		vwy;
	float		wh;
}				t_map;

typedef struct	s_header{
	int			file_size;
	int			off_bits;
	int			size;
	int			info_size;
	int			planes;
	int			bit_count;
	int			image_size;
	int			width_in_bytes;
	int			fd;
}				t_header;

t_xpm			g_xpm;
t_tool			g_tool;
t_map			g_map;
t_sprite		*g_sp;

void			ft_square(void *ptr, void *win);
void			init(void);
void			ft_gnl(int fd);
int				checking(char *cub);
void			ft_circle(int a, int b, int colour);
int				end(int x, void *s);
void			ta_sir(char *s);
void			chk_err(char *s, int fd);
void			chk_cf(char *s, int fd);
void			chk_resolution(char *s, int fd);
int				countchars(char *s, char c);
int				alldigs(char *s, int len);
int				doublecount(char **s);
void			doublefree(char **ptr);
void			affect_coulour(char **colour, char c, char **hold);
int				reversecheck(char *s, char *str);
void			other(char *s, int fd);
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
int				casth(void);
int				castv(void);
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
void			draw_one_pixel(int y, int x, double color);
void			draw_sprites(int x, double distance, double height);
void			render_sprite(void);
int				chk_file(char *f);
void			save_flag(char *s);
int				same(char *s1,char *s2);
void			make_a_bmp(void);
int				ft_atoi(const char *str);
int	ft_isdigit(int a);
int	ft_memcmp(const void *buf1, const void *buf2, size_t count);
void	*ft_memcpy(void *to, const void *from, size_t n);
void	*ft_memset(void *buf, int x, size_t count);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char		**ft_split(char const *s, char c);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
int	ft_strncmp(const char *str1, const char *str2, size_t n);
size_t	ft_strle(const char *str);
char	*ft_strdu(const char *str);
char	*ft_strjoi(char const *s1, char const *s2);
char	*ft_strch(const char *str, int c);
char	*ft_subst(char const *s, unsigned int start, size_t len);
int			get_next_line(int fd, char **line);
#endif
