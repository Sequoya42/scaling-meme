/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 22:21:23 by rbaum             #+#    #+#             */
/*   Updated: 2016/04/18 22:21:30 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int						rainbow_color(int x, int y)
{
	register double		c;
	register int		red;
	register int		green;
	register int		blue;


	c = x * (y + 1);
	red = cos(c) * 127 + 128;
	green = tan(c ) * 127 + 128;
	blue = sin(c ) * 127 + 128;
	return ((red << 16) + (blue << 8) + green);
}

void 				draw_circle(t_env *e, int x, int y, int l)
{
	register int ang = 0;
	int c = 0;
	while (ang <= 360)
	{
		c = rainbow_color(x, ang);
		draw_polar(x, y, ang, l, e, c);
		draw_polar(y, x, ang, l, e, c);
		ang+= e->inc;
	}
}
