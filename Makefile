# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/12 12:28:14 by mmarzouk          #+#    #+#              #
#    Updated: 2020/12/06 13:06:19 by mmarzouk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all :
	gcc -I /usr/local/include *.c */*.c -lmlx -framework OpenGL -framework AppKit  
	./a.out map3.cub --save
deb :
	gcc -I /usr/local/include *.c */*.c -lmlx -framework OpenGL -framework AppKit -g
	
san:
	gcc -I /usr/local/include *.c */*.c -lmlx -framework OpenGL -framework AppKit -fsanitize=address
	./a.out