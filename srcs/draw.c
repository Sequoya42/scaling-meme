/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 18:46:00 by rbaum             #+#    #+#             */
/*   Updated: 2015/02/05 18:36:14 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void				print_old(t_env *e)
{
	int i = -1;
	while (++i < e->inc)
	{
		printf("i : %d\t\txo : %d \t\tyo : %d\n", i, e->xo[i], e->yo[i]);
	}
	printf("xn : %d\t\tyn : %d \n", e->xn, e->yn);
}

void				draw_triangle(t_env *e)
{
		int length = WIDTH - OFF;
		init_value(e);
		draw_polar(e->xn, e->yn, 180, length, e, RED);
		draw_polar(e->xn, e->yn, 60, length, e, GREEN);
		draw_polar(e->xn, e->yn, 300, length, e, BLUE);
		fdf_draw_line(e, XO, XO, YO, LY, YELLOW);
		e->mp = XN;
		e->xsym = e->mp;
		e->ysym = YN;
		draw_outer_circle(length, e);
}

void		draw_polar(int x, int y, int angle, int r, t_env *e, int color)
{
	int		x1;
	int		y1;
	double 	ang;
	ang = angle * D;
	x1 = x - r * (cos(ang));
	y1 = y - r * (sin(ang));
	e->a = abs(x1 - x);
	e->b = abs(y1 - y);
	// printf("a : %d \t\t b: %d\n", e->a, e->b);
	fdf_draw_line(e, x, x1, y, y1, color);
}

void				do_the_thing(t_env *e, float angle, int length, int change)
{
	(void)change;
	while (e->inc < 13)
	{
		// length = LY - e->yn;
		length = e->b;
		draw_polar(e->xn, e->yn, 270, length, e, VIOLET);
		length = e->mp - e->xn;
		e->mp = e->xn;
		draw_polar(XO, YO, 180, length, e, BLUE);
		length = get_both(XX(1), YY(1), LX, LY, e);
		draw_polar(XO, YO, angle, length, e, ORANGE);
	}
}
// 367

void				draw_orange(t_env *e, int i)
{
	int length = get_both(e->xsym, e->yo[i] , e->xo[i], e->yo[2], e);
	draw_polar(e->xsym, e->yo[i], e->beta, length, e, ORANGE);
}

// void				draw_red(t_env *e, int i, int sx)
// {
// 	int length = get_both(e->xo[sx], e->yo[i] , e->xo[i], e->yo[i + 1], e);
// 	draw_polar(e->xo[i + 1], e->yo[i + 1], e->beta, length, e, RED);
// }


void				draw_violet(t_env *e, int a)
{
	int length = e->b;
	draw_polar(e->xn, e->yn, a, length, e, VIOLET);
	e->mp = e->xn;
	e->yp = e->yn;
}
void				draw_blue(t_env *e, int i)
{
	int length = e->xsym - e->xo[INC];
	draw_polar(XX(1 + i), YY(1 + i), 180, length, e, BLUE);
}

void				draw_yellow(t_env *e, int i)
{
	(void)i;
	int length = get_both(e->xn, e->yn, e->xo[INC - 1], e->yp, e);
	draw_polar(e->xsym, e->yn, e->beta - 90,  length, e, YELLOW);
	draw_violet(e, 90);
	draw_blue(e, 1);
	// draw_light_red(e, 1);
	// draw_light_red(e, i);
}

void				draw_green(t_env *e)
{
	int length = get_both(e->xn, e->yn, e->xsym, e->yo[INC], e);
	// ft_putnbrendl(length);
	draw_polar(e->xn, e->yn, 180 - e->alpha, length, e, GREEN);
	length = e->b;
	draw_false_shit(e->xn, e->yn, 270, length, e, VIOLET);
}

void				ft_more(t_env *e, int i)
{
	draw_orange(e, i);
	draw_violet(e, 270);
	draw_green(e);
	// draw_green(e);
	draw_blue(e, 0);
	draw_yellow(e, 0);
	// draw_red(e, 5, 3);
	// draw_red(e, i + 2);
	// draw_violet
}


int					draw(t_env *e)
{
	draw_triangle(e);
	// do_the_thing(e, e->beta, 0, 0);
	ft_more(e, 3);
	// ft_more(e, 5);
	// ft_more(e, 11	);
	int i = 5;
	while (i < 51)
	{
		ft_more(e, i);
		i+= 7;
	}
	// print_old(e);
	return (0);	
}
