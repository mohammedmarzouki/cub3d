/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 07:27:16 by mmarzouk          #+#    #+#             */
/*   Updated: 2020/12/16 16:52:35 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
/*
#define M_E         2.71828182845904523536028747135266250    |e              
#define M_LOG2E     1.44269504088896340735992468100189214    |log2(e)        
#define M_LOG10E    0.434294481903251827651128918916605082   |log10(e)       
#define M_LN2       0.693147180559945309417232121458176568   |loge(2)        
#define M_LN10      2.30258509299404568401799145468436421    |loge(10)       
#define M_PI        3.14159265358979323846264338327950288    |pi             
#define M_PI_2      1.57079632679489661923132169163975144    |pi/2           
#define M_PI_4      0.785398163397448309615660845819875721   |pi/4           
#define M_1_PI      0.318309886183790671537767526745028724   |1/pi          
#define M_2_PI      0.636619772367581343075535053490057448   |2/pi           
#define M_2_SQRTPI  1.12837916709551257389615890312154517    |2/sqrt(pi)     
#define M_SQRT2     1.41421356237309504880168872420969808    |sqrt(2)       
#define M_SQRT1_2   0.707106781186547524400844362104849039   |1/sqrt(2)      
*/
void init(void)
{
	g_ptr = mlx_init();
    g_tool.x = 20;
    g_tool.y = 30;
	g_tool.readingmap = 0;
	g_tool.cntplyr = 0;
	g_xpm.no =  NULL;
	g_xpm.so =  NULL;
	g_xpm.ea =  NULL;
	g_xpm.we =  NULL;
	g_xpm.s =  NULL;
	g_tool.vars.carrier = ft_strdup("");
}
void 	draw_line(int x ,int y,int x1,int y1)
{
	int dx;
	int dy;
	float x_inc;
	float y_inc;
	int steps;

	dx = x - x1;
	dy = y - y1;
	steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
	x_inc = dx/(float)steps;
	y_inc = dy/(float)steps;
	float  b0 = x;
    float  c0 = y;
	while (steps--)
	{
		g_screen[((int)c0 * g_tool.xa + (int)b0)] = violet;
		b0 += x_inc;
		c0 += y_inc;
	}
}
// void draw_line(int X0, int Y0, int X1, int Y1) 
// { 
//     // calculate dx & dy 
//     int dx = X1 - X0; 
//     int dy = Y1 - Y0; 
  
//     // calculate steps required for generating pixels 
//     int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy); 
  
//     // calculate increment in x & y for each steps 
//     float Xinc = dx / (float) steps; 
//     float Yinc = dy / (float) steps; 
  
//     // Put pixel for each step 
//     float X = X0; 
//     float Y = Y0; 
//     for (int i = 0; i <= steps; i++) 
//     { 
//         g_screen[(int)floor(X * g_tool.xa + Y)] = violet;  // put pixel at (X,Y) 
//         X += Xinc;           // increment in x at each step 
//         Y += Yinc;           // increment in y at each step          // for visualization of line- 
//                              // generation step by step 
//     } 
// } 
void ft_circle(int x,int y,int colour)
{
	int k;
	int a ;
	int b ;
	int r = 5;

	
	a = 0;
	b = 0;
	k = b;
	while(a < g_tool.xa)
	{
		b = k;
		while(b < g_tool.ya)
		{
			if(pow((a - x),2)+pow((b - y),2) <= pow(r,2))
				{
					g_screen[(b * g_tool.xa + a)] = violet;
				}
			b++;
		}
		a++;
	}
}