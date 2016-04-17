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
		fdf_draw_line_t1(e);
		fdf_draw_line_t2(e);
		fdf_draw_line_t3(e);
}

int					draw(t_env *e)
{
	int 		i;
	int 		j;

	i = 0;
	j = 0;
	draw_triangle(e);
	return (0);	
}