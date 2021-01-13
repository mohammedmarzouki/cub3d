/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:33:44 by mmarzouk          #+#    #+#             */
/*   Updated: 2021/01/13 14:49:23 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

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

typedef struct	s_bmp{
	int			image_s;
	int			width_bytes;
}				t_bmp;

#endif
