/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gpu_frac.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoussau <antoine@doussaud.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 20:10:19 by adoussau          #+#    #+#             */
/*   Updated: 2015/02/03 20:10:21 by adoussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		cuda_mandelbrot(t_all *all)
{
	t_pos		pt;
	int			o;

	o = 0;
	CALL_MANDELBROT;
	pt.y = MENU_MAX_Y;
	while (pt.y < WIN_SZ_Y)
	{
		pt.x = 0;
		while (pt.x < WIN_SZ_X)
		{
			color_frac(all->tab[o], all);
			ft_put_pxl(all, &pt);
			pt.x++;
			o++;
		}
		pt.y++;
	}
	if (all->filter > 0)
		color_renorm(all, pt);
}

void		cuda_julia(t_all *all)
{
	t_pos		pt;
	int			o;

	CALL_JULIA;
	pt.y = MENU_MAX_Y;
	o = 0;
	while (pt.y < WIN_SZ_Y)
	{
		pt.x = 0;
		while (pt.x < WIN_SZ_X)
		{
			color_frac(all->tab[o], all);
			ft_put_pxl(all, &pt);
			pt.x++;
			o++;
		}
		pt.y++;
	}
	if (all->filter > 0)
		color_renorm(all, pt);
}

void		cuda_douady(t_all *all)
{
	t_pos		pt;
	int			o;

	o = 0;
	CALL_DOUADY;
	pt.y = MENU_MAX_Y;
	while (pt.y < WIN_SZ_Y)
	{
		pt.x = 0;
		while (pt.x < WIN_SZ_X)
		{
			color_frac(all->tab[o], all);
			ft_put_pxl(all, &pt);
			pt.x++;
			o++;
		}
		pt.y++;
	}
	if (all->filter > 0)
		color_renorm(all, pt);
}
