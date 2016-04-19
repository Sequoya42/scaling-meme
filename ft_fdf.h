/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 15:33:11 by rbaum             #+#    #+#             */
/*   Updated: 2016/03/12 15:31:24 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

#include <stdio.h>
# include <math.h>
# include "../minilibx_macos/mlx.h"
# include <fcntl.h>
# include "misc.h"
# include "libft/libft.h"


typedef struct			s_img
{
	char				*d;
	int					bpp;
	int					endian;
	int					line_size;
	void				*img;
}						t_img;


typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_img			*f;
	//TRIANGLE STUFF
	int				xa;
	int				xb;
	int				xc;
	int				ya;
	int				yb;
	int				yc;
	int				xn;
	int				yn;
	int				xo[16];
	int				yo[16];
	//SIDE OF TRIANGLE
	int				a;
	int				b;
	int				c;
	int				length;
	int				angle;
	int				inc;
}					t_env;

int			flemme_draw_line(t_env *e, int x1, int x2, int y1, int y2, int color);
void				ft_calc_pixel(t_env *e, int i, int j);
void				get_real_coord(t_env *e);
void				ft_put_pixel(t_env *e, int i, int j);
void				ft_mlx(t_env *e);

int					draw(t_env *e);
int					fdf_draw_line(t_env *e, int x1, int x2, int y1, int y2, int color);
int					expose_hook(t_env *e);
int					key_hook(int keycode, t_env *e);
int					main(int ac, char **av);
void				put_pixel(t_img *e, int x, int y, int color);
int					try_color(int red, int blue, int green);
void 				draw_circle(t_env *e, int x, int y, int l);
void				draw_polar(int x, int y, int angle, int r, t_env *e, int color);
#endif
