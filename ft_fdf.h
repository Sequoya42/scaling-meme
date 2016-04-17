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

# include <math.h>
# include <mlx.h>
# include <fcntl.h>
# include "misc.h"
# include "libft/libft.h"


typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*content;
	//TRIANGLE STUFF
	int				xa;
	int				xb;
	int				xc;
	int				ya;
	int				yb;
	int				yc;
	int				a;
	int				b;
	int				c;
}					t_env;


void				ft_calc_pixel(t_env *e, int i, int j);
void				get_real_coord(t_env *e);
void				ft_put_pixel(t_env *e, int i, int j);
void				ft_mlx(t_env *e);

int					draw(t_env *e);
int					fdf_draw_line_t1(t_env *e);
int					fdf_draw_line_t2(t_env *e);
int					fdf_draw_line_t3(t_env *e);
int					expose_hook(t_env *e);
int					key_hook(int keycode, t_env *e);
int					main(int ac, char **av);

#endif
