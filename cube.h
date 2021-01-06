#ifndef CUBE_H 
# define CUBE_H
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include "gnl/get_next_line.h"
#include "libft/libft.h"

void *g_ptr;//initialisation pointer
void *g_win;//the window pointer
void *g_image;//image pointer
int *g_screen;//image array
#define violet 0xabcabc
#define W 13
#define S 1
#define A 0
#define D 2
#define STP 20
#define FOV (M_PI / 3)
#define DIV 1
#define TS 170



typedef struct s_freD
{
    char **hold;
    char **colour;
    char *carrier;
} t_free;

typedef struct s_tool
{
    int x;//the moving x index
    int y;//the moving y index
    int a;//last x point in the square
    int b;//last y point in the square
    int xa;//the x resolution "1080"
    int ya;//the y resolution "720"
    int cr;//ceiling red
    int cg;//ceiling green
    int cb;//ceiling blue
    int fr;//floor red
    int fg;//floor green
    int fb;//floor blue
    int resflag;//True when resolution exist
    int cflag;//true when color exist
    int fflag;//true when floor exist
    int readingmap;//true when reading map
    int cntplyr;//count player
    int rows;
    int cols;
    int sprites;//sprite count
    t_free vars;
} t_tool;


typedef struct s_xpm
{
    int *no;
    int *so;
    int *ea;
    int *we;
    int *s;
    int now;
    int noh;
    int sow;
    int soh;
    int eaw;
    int eah;
    int wew;
    int weh;
    int sw;
    int sh;

} t_xpm;
typedef struct s_sprite
{
    float   x;
    float   y;
    float   d;
    int     a;
    int     b;
}               t_sprite;

typedef struct s_map
{
    char    **map;
    int     *txt;
    int     txth;
    int     txtw;
    int     down;
    int     up;
    int     left;
    int     right;
    int     no;
    int     so;
    int     ea;
    int     we;
    char    hov;
    float   ppx;
    float   ppy;
    float   pdrct;
    float   nppx;
    float   nppy;
    float   rayd;
    float   wx;
    float   wy;
    float   dis;
    float   hwx;
    float   hwy;
    float   vwx;
    float   vwy;
    float   wh;
} t_map;



t_xpm g_xpm;
t_tool g_tool;
t_map g_map;
//t_sprite g_sp;

void    ft_square(void *ptr,void *win);
void    init(void);
void    ft_gnl(void);
int     checking(char *cub);
void    ft_circle(int a,int b,int colour);
int     end(int x,void *s);
void    ta_sir(char *s);
void    chk_err(char *s, int fd);
void    chk_cf(char *s,int fd);
void    chk_resolution(char *s,int fd);
int     countchars(char *s ,char c);
int     alldigs(char *s,int len);
int     doublecount(char **s);
void    doublefree(char **ptr);
void    affect_coulour(char **colour,char c,char **hold);
int     reversecheck(char *s,char *str);
void    other(char *s,int fd);
int     alldone(void);
void    affect_xpm(void	*xpm_ptr);
int     itismap(char *s);
int     allspaces(char *s);
void    save_map(char *s);
void    handling_errors(void);
void    handling_map(int i);
void    resizing_map(int i,int big_len);
void    check_map_errors(int max_x,int max_y);
void    drawmap(void);
int		trgb(int t, int r, int g, int b);
void    square(int x,int y,int lenght,int colour);
void    drawplayer(void);
void    draw_line(float x ,float y,float x1,float y1);
void    init_values(void);
void    render(void);
void    player_position(int *x, int *y);
void    wall(void);
void    correcting_angle(void);
int     is_wall(float x ,float y);
void    ft_fov(void);
void    draw_walls(float x,float y);
float   distance(float x,float y,float x2,float y2);
void 	a_line(float x ,float y,float x1,float y1);
void    raycast(void);
void    ray_direction(void);
int     casth(void);
int     castv(void);
void    def_dir(void);
void    find_texture(void);
void    ptr_wh(int x,int y);
void    put_texture(float x,float y);
void    floor_ceiling(void);
void    get_center( float *x, float *y);
void    countsprites(void);
#endif 