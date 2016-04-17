/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 00:22:56 by rbaum             #+#    #+#             */
/*   Updated: 2016/03/12 15:31:53 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		fdf_draw_line_t1(t_env *e)
{
	int dx;
	int dy;
	int color;

	color = RED;
	dx = (e->xb - e->xa);
	dy = (e->yb - e->ya);
	if (abs(dx) > abs(dy))
		while (dx += (dx < 0) - (dx > 0))
			mlx_pixel_put(e->mlx, e->win, e->xa + dx,
e->ya + dx * (e->yb - e->ya) / (e->xb - e->xa), color);
	else
		while (dy += (dy < 0) - (dy > 0))
			mlx_pixel_put(e->mlx,
e->win, e->xa + dy * (e->xb - e->xa) / (e->yb - e->ya),
e->ya + dy, color);
	return (0);
}

int		fdf_draw_line_t2(t_env *e)
{
	int dx;
	int dy;
	int color;

	color = GREEN;
	dx = (e->xc - e->xa);
	dy = (e->yc - e->ya);
	if (abs(dx) > abs(dy))
	{
		while (dx += (dx < 0) - (dx > 0))
			mlx_pixel_put(e->mlx, e->win, e->xa + dx,
e->ya + dx * (e->yc - e->ya) / (e->xc - e->xa), color);
	}
	else
	{
		while (dy += (dy < 0) - (dy > 0))
			mlx_pixel_put(e->mlx,
e->win, e->xa + dy * (e->xc - e->xa) / (e->yc - e->ya),
e->ya + dy, color);
	}
	return (0);
}

int		fdf_draw_line_t3(t_env *e)
{
	int dx;
	int dy;
	int color;

	color = BLUE;
	dx = (e->xc - e->xb);
	dy = (e->yc - e->yb);
	if (abs(dx) > abs(dy))
	{
		while (dx += (dx < 0) - (dx > 0))
			mlx_pixel_put(e->mlx, e->win, e->xb + dx,
e->yb + dx * (e->yc - e->yb) / (e->xc - e->xb), color);
	}
	else
	{
		while (dy += (dy < 0) - (dy > 0))
			mlx_pixel_put(e->mlx,
e->win, e->xb + dy * (e->xc - e->xb) / (e->yc - e->yb),
e->yb + dy, color);
	}
	return (0);
}

