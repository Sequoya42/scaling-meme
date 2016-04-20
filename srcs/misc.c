/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 15:03:47 by rbaum             #+#    #+#             */
/*   Updated: 2016/04/20 15:03:51 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void		draw_false_shit(int x, int y, int angle, int r, t_env *e, int color)
{
	int		x1;
	int		y1;
	double 	ang;
	ang = angle * D;
	x1 = x - r * (cos(ang));
	y1 = y - r * (sin(ang));
	flemme_draw_line(e, x, x1, y, y1, color);
}

void		test_misc(int x, int y, int angle, int r, t_env *e, int color)
{
	int		x1;
	int		y1;
	double 	ang;
	ang = angle * D;
	x1 = x - r * (cos(ang));
	y1 = y - r * (sin(ang));
	// flemme_draw_line(e, x, x1, y, y1, color);
	// flemme_draw_line(e, x, y, x1, y1, color);
	// flemme_draw_line(e, x1, y1, x, y, color);
	flemme_draw_line(e, x1, y, x, y1, color);
}

void				draw_outer_circle(int length, t_env *e)
{
		int r = LY - (length / (2 * sqrt(3)));
		int a = -1;
		while (++a < 360)
			draw_false_shit(e->xsym, r , a, length *(sqrt(3) / 3), e, BLUE);
		put_pixel(e->f, e->xsym, r, RED);
}

void				get_abc(int x1, int y1, int x2, int y2, t_env *e)
{
	e->a = abs(y1 - y2);
	e->b = abs(x1 - x2);
	e->c = sqrt((e->a * e->a) + (e->b * e->b));
}

void				get_length(t_env *e)
{
	e->length = abs(e->a * e->b / e->c);
}

int					get_both(int x1, int y1, int x2, int y2, t_env *e)
{
	get_abc(x1, y1, x2, y2, e);
	get_length(e);
	return (e->length);
}
