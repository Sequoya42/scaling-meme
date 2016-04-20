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

# define INC	(e->inc - 2)
# define XO		(e->xo[INC])
# define YO		(e->yo[INC])
# define XX(x)	(e->xo[INC - x])
# define YY(x)	(e->yo[INC - x])
# define LX		(e->xo[0])
# define LY		(e->yo[0])
# define XN		(e->xo[e->inc - 1])
# define YN		(e->yo[e->inc - 1])
# define SYM(x) (x + ((e->xsym - x) * 2))
	
# define HEIGHT 820	
# define WIDTH 	820
# define OFF 	100

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
# define YELLOW	0xE9B21C
# define VIOLET	0x6E47CA
# define ORANGE	0xFF5B2B
# define LGRN	0xAEEE00
# define LRED	0x8E3557
# define LYEL	0xFFDA8C

# define D      (double)(M_PI / 180.0)
#endif