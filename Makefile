# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/12 12:28:14 by mmarzouk          #+#    #+#              #
#    Updated: 2021/01/11 16:13:48 by mmarzouk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3D
WWW = -Wall -Wextra -Werror
MLX = /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
SRC = assets/drawdim.c assets/drawmap2d.c assets/err_handle1.c \
	assets/err_handle2.c assets/field_of_view.c assets/ft_atoi.c assets/ft_gnl.c \
	assets/ft_isdigit.c assets/ft_memcmp.c assets/ft_memcpy.c assets/ft_memset.c \
	assets/ft_putchar_fd.c assets/ft_putstr_fd.c assets/ft_split.c assets/ft_start.c\
	assets/ft_strchr.c assets/ft_strdup.c assets/ft_strjoin.c assets/ft_strlen.c \
	assets/ft_strncmp.c assets/get_next_line_utils.c assets/get_next_line.c \
	assets/main.c assets/make_bmp.c assets/sprites.c assets/sprites2.c\
	assets/tools.c assets/tools2.c assets/values.c assets/getting_value.c

all : $(NAME)

$(NAME) :
	@gcc -o $(NAME) $(WWW) $(SRC) -L $(MLX) 

clean :
	@rm -rf screenshot.bmp

fclean: clean
	@rm -rf cub3D

re: fclean all
		