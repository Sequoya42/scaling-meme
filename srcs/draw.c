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

void				get_real_coord(t_env *e)
{
	e->xa = WIDTH / 2;
	e->xb = OFF;
	e->xc = WIDTH - OFF;
	e->ya = OFF;
	e->yb = HEIGHT - OFF;
	e->yc = HEIGHT - OFF;
}

void				draw_triangle(t_env *e)
{
		get_real_coord(e);
		flemme_draw_line(e, e->xa, e->xb, e->ya, e->yb, RED);
		flemme_draw_line(e, e->xc, e->xa, e->yc, e->ya, GREEN);
		flemme_draw_line(e, e->xb, e->xc, e->yb, e->yc, BLUE);
		// draw_mid_section to get two right angle triangles
		fdf_draw_line(e, e->xa, e->xa, e->ya, e->yb, YELLOW);
}

void		draw_polar(int x, int y, int angle, int r, t_env *e, int color)
{
	int		x1;
	int		y1;
	double 	ang;
	ang = angle * D;
	x1 = x - r * (cos(ang));
	y1 = y - r * (sin(ang));
	fdf_draw_line(e, x, x1, y, y1, color);
	//for trippy stuff with draw circle
	// fdf_draw_line(e, x, y, x1, y1, color);
	// fdf_draw_line(e, x1, y1, x, y, color);
	// fdf_draw_line(e, x1, y, x, y1, color);
}


int					get_length(int x1, int y1, int x2, int y2, t_env *e)
{
	int				length;
	int				a;
	int				b;
	int				c;

	a = abs(y1 - y2);
	b = abs(x1 - x2);
	c = sqrt((a * a) + (b * b));
	length = abs(a * b / c);
	e->a = a;
	e->b = b;
	e->c = c;
	e->length = length;
	return (length);
}

void				do_the_thing(t_env *e, float angle, int length, int change)
{
	(void)change;
	draw_polar(e->xa, e->yb, angle, length, e, ORANGE);
	// draw_polar(e->xn, e->yn,135 + angle, length, e, LG);
	fdf_draw_line(e, e->xn, e->xn, e->yn, e->yb, VIOLET);
	length = get_length(e->xn, e->yo[e->inc - 1], change, e->yb ,e);
	draw_polar(e->xn, e->yn, angle, length, e, YELLOW);
	fdf_draw_line(e, e->xn, e->xn, e->yn, e->yb, VIOLET);
	flemme_draw_line(e, e->xn, e->xa, e->yo[e->inc - 3], e->yo[e->inc - 3], GREEN);
}

int					draw(t_env *e)
{
	float				angle;
	int				length;

	draw_triangle(e);
	length = get_length(e->xa, e->ya, e->xb, e->yb, e);
	angle = atan((float)e->b / (float)e->a) / D;
	do_the_thing(e, angle, length, e->xb);
	// fdf_draw_line(e, e->xo, e->xo, e->yo, e->yb / 2, GREEN);
	// draw_polar()
	do_the_thing(e, 180 - angle, length, e->xc);
	return (0);	
}
















