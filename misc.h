/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 11:32:10 by rbaum             #+#    #+#             */
/*   Updated: 2016/04/17 11:32:12 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISC_H

# define MISC_H

# define MOTION_NOTIFY          8
# define PTR_MOTION_MASK        (1 << 8)

# define STARTX (200)
# define STARTY (100)
# define INC e->zoom
# define HEIGHT 1200
# define WIDTH 	1700
# define OFF 	100
# define YOFF	e->off2
# define SX1 	e->coord[i][0]->size_x
# define SX2 	e->coord[i + 1][0]->size_x

# define MK_UP  126
# define MK_DW  125
# define MK_LT  123
# define MK_RT  124

# define MK_Z   6
# define MK_C   8
# define MK_F   3
# define MK_D   2
# define MK_H   4
# define MK_R   15
# define MK_B   11
# define MK_N   45

# define MK_ESC 53
# define MK_PL  69
# define MK_MI  78

# define MB_L   1
# define MB_R   2
# define MB_M   3
# define MB_UP  5
# define MB_DW  4

# define BLUE	0X048B9A
# define GREEN	0x1A9026
# define RED	0xA1124B

#endif