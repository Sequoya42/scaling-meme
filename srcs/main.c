/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 08:50:24 by rbaum             #+#    #+#             */
/*   Updated: 2016/03/12 15:34:20 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		expose_hook(t_env *e)
{
	draw(e);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	if (keycode == MK_ESC)
		exit(0);
	expose_hook(e);
	return (0);
}



void	ft_mlx(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "triangle_try_angle");
	mlx_key_hook(e->win, key_hook, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_hook(e->win, MOTION_NOTIFY, PTR_MOTION_MASK, key_hook, e);
	mlx_loop(e->mlx);
}

int		main(int ac, char **av)
{
	t_env *e;

	(void)ac;
	(void)av;
	if ((e = (t_env *)malloc(sizeof(t_env))) == NULL)
		exit(0);
	ft_mlx(e);
	return (0);
}
