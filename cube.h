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

typedef struct s_free
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
    int cntplyr;//count palyer
    t_free vars;
} t_tool;


typedef struct s_xpm
{
    int *no;
    int *so;
    int *ea;
    int *we;
    int *s;
} t_xpm;
typedef struct s_map
{
    char **map;
    int ppx;
    int ppy;
    float pdrct;
} t_map;

t_xpm g_xpm;
t_tool g_tool;
t_map g_map;

void    ft_square(void *ptr,void *win);
void    init(void);
void    ft_gnl(void);
int     checking(char *cub);
void    ft_circle(void *ptr,void *win);
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
#endif 