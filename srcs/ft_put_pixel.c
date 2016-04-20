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

void					put_pixel(t_img *e, int x, int y, int color)
{
	const unsigned int	bytes = e->bpp / 8;
	const unsigned int	p = x * bytes + y * e->line_size;
	size_t				i;

	i = 0;
	while (i < bytes)
	{
		e->d[p + i] = color;
		color >>= 8;
		i++;
	}
}

int						try_color(int red, int blue, int green)
{
    return ((red << 16) + (blue << 8) + green);
}

int			fdf_draw_line(t_env *e, int x1, int x2, int y1, int y2, int color)
{
		int dx;
		int dy;
	
	dx = (x1 - x2);
	dy = (y1 - y2);
	if (abs(dx) > abs(dy))
	{
		while ((dx += (dx < 0) - (dx > 0)))// && (e->xn < WIDTH && e->yn < HEIGHT))
		{
				e->xn = x2 + dx;
				e->yn = y2 + dx * (y1 - y2) / (x1 - x2);
			put_pixel(e->f, e->xn, e->yn, color);
			if (e->inc > 4) put_pixel(e->f, SYM(e->xn), e->yn, color);
		}
	}
	else
	{
		while ((dy += (dy < 0) - (dy > 0)))// && (e->xn < WIDTH && e->yn < HEIGHT))
		{
			e->xn = x2 + dy * (x1 - x2) / (y1 - y2);
			e->yn = y2 + dy;
			put_pixel(e->f, e->xn, e->yn, color);
			if (e->inc > 4) put_pixel(e->f, SYM(e->xn), e->yn, color);
		}
	}
	mlx_put_image_to_window(e->mlx, e->win, e->f->img, 0, 0);
	e->xo[e->inc] = e->xn;
	e->yo[e->inc++] = e->yn;
	return (0);
}

int			flemme_draw_line(t_env *e, int x1, int x2, int y1, int y2, int color)
{
		int dx;
		int dy;
	
	dx = (x1 - x2);
	dy = (y1 - y2);
	if (abs(dx) > abs(dy))
	{
		while (dx += (dx < 0) - (dx > 0))
		{
			if (e->inc > 7)
			{
			put_pixel(e->f, x2 + dx, y2 + dx * (y1 - y2) / (x1 - x2), color);
			if (e->inc < 40)
			put_pixel(e->f, SYM(x2 + dx), y2 + dx * (y1 - y2) / (x1 - x2), color);
			}
		}
		put_pixel(e->f, x2 + dx, y2 + dx * (y1 - y2) / (x1 - x2), color);
	}
	else
	{
		while (dy += (dy < 0) - (dy > 0))
		{
			if (e->inc > 7)
			{
			put_pixel(e->f, x2 + dy * (x1 - x2) / (y1 - y2),y2 + dy, color);
			if (e->inc < 40)
			put_pixel(e->f, SYM(x2 + dy * (x1 - x2) / (y1 - y2)),y2 + dy, color);
			}
		}
			put_pixel(e->f, x2 + dy * (x1 - x2) / (y1 - y2),y2 + dy, color);
	}
	mlx_put_image_to_window(e->mlx, e->win, e->f->img, 0, 0);
	return (0);
}


