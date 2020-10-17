# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/12 12:28:14 by mmarzouk          #+#    #+#              #
#    Updated: 2020/10/14 14:29:02 by mmarzouk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all :
	gcc -I /usr/local/include *.c */*.c -lmlx -framework OpenGL -framework AppKit 
	./a.out
deb :
	gcc -I /usr/local/include *.c */*c -lmlx -framework OpenGL -framework AppKit -g