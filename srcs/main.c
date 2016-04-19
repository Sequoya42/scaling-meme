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

void	ft_test(t_env *e)
{
	int x = 0;
	int y = 0;
	int c = try_color(0, 20, 0);
	while (x++ < WIDTH)
	{
		y = 0;
		while (y++ < HEIGHT)
			put_pixel(e->f, x, y, c);
	}
	mlx_put_image_to_window(e->mlx, e->win, e->f->img, 0, 0);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == MK_C)
		mlx_clear_window(e->mlx, e->win);
	else if (keycode == MK_ESC)
		exit(0);
	else if (keycode == MK_Z)
		ft_test(e);
	else if (keycode == MK_H)
		draw(e);
	else if (keycode == MK_N)
	{
		printf("e->xn\t%d\t\te->yn\t%d\ne->xo\t%d\t\te->yo\t%d\n", e->xn, e->yn, e->xo[e->inc - 1], e->yo[e->inc - 1]);
	}
	return (0);
}

int						mouse_hook(int button, int x, int y, t_env *e)
{
	if ((button == MB_L || button == MB_UP) && x <= WIDTH && y <= HEIGHT)
	{
		// printf("x \t %d \t\ty \t %d\n", x, y);
		// printf("\t\txn \t %d \t\t yn \t %d \n", e->xn, e->yn);
		put_pixel(e->f, x, y, RED);
	}
		mlx_put_image_to_window(e->mlx, e->win, e->f->img, 0, 0);
	return (draw(e));
}


void	ft_mlx(t_env *e)
{
	e->f = malloc(sizeof(t_img));
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "triangle_try_angle");
	e->f->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->f->d = mlx_get_data_addr(e->f->img, &e->f->bpp, &e->f->line_size, &e->f->endian);
	mlx_key_hook(e->win, key_hook, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_loop(e->mlx);
	e->inc = 0;
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
