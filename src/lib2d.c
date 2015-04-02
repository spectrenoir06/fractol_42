/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoussau <antoine@doussaud.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 20:10:49 by adoussau          #+#    #+#             */
/*   Updated: 2015/02/03 20:10:56 by adoussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color		ft_rgb_to_color(UCHAR r, UCHAR g, UCHAR b)
{
	t_color		color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

int			ft_color_to_int(t_color color)
{
	int		c;

	c = color.r;
	c = c << 8;
	c += color.g;
	c = c << 8;
	c += color.b;
	return (c);
}

t_color		ft_int_to_color(int i)
{
	t_color		c;

	c.b = i & 0xFF;
	i = i >> 8;
	c.g = i & 0xFF;
	i = i >> 8;
	c.r = i & 0xFF;
	return (c);
}

void		ft_put_pxl(t_all *all, t_pos *pt)
{
	*((int *)&all->img.data[(int)(pt->y * all->img.sizeline + pt->x *
	all->inc)]) = all->img.clrline;
}
