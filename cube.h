#ifndef CUBE_H 
# define CUBE_H
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "gnl/get_next_line.h"
//#include "libft/libft.h"

void *g_ptr;
void *g_win;
void *g_image;
int *g_screen;

typedef struct s_tool
{
    int x;
    int y;
    int a;
    int b;
    int xa;
    int ya;
} t_tool;
t_tool g_tool;

void ft_square(void *ptr,void *win);
void init(void);
void ft_gnl(void);

#endif 