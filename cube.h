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

typedef struct s_tool
{
    int x;//the moving x index
    int y;//the moving y index
    int a;//last x point in the square
    int b;//last y point in the square
    int xa;//the x resolution "1080"
    int ya;//the y resolution "720"
} t_tool;
t_tool g_tool;

void    ft_square(void *ptr,void *win);
void    init(void);
void    ft_gnl(void);
int     checking(char *cub);
void    ft_circle(void *ptr,void *win);
int     end(int x,void *s);
void    ta_sir(char *s);

#endif 