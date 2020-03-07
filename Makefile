# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/12 12:28:14 by mmarzouk          #+#    #+#              #
#    Updated: 2020/03/03 14:17:48 by mmarzouk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all :
	gcc -I /usr/local/include *.c */*.c -lmlx -framework OpenGL -framework AppKit 
	./a.out
deb :
	gcc -I /usr/local/include *.c -lmlx -framework OpenGL -framework AppKit 

	