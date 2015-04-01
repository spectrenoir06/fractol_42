/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpu_frac.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoussau <antoine@doussaud.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 20:10:10 by aalliot           #+#    #+#             */
/*   Updated: 2015/02/03 20:10:12 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "fractol.h"

void		color_frac(int i, t_all *all)
{

	int tab[] = {
	0x0000FF,
	0x0C00FF,
	0x1800FF,
	0x2400FF,
	0x3000FF,
	0x3C00FF,
	0x4800FF,
	0x5400FF,
	0x6100FF,
	0x6D00FF,
	0x7900FF,
	0x8500FF,
	0x9100FF,
	0x9D00FF,
	0xAA00FF,
	0xB600FF,
	0xC200FF,
	0xCE00FF,
	0xDA00FF,
	0xE600FF,
	0xF200FF,
	0xFF00FF,
	0xFF00F2,
	0xFF00E6,
	0xFF00DA,
	0xFF00CE,
	0xFF00C2,
	0xFF00B6,
	0xFF00AA,
	0xFF009D,
	0xFF0091,
	0xFF0085,
	0xFF0079,
	0xFF006D,
	0xFF0061,
	0xFF0055,
	0xFF0048,
	0xFF003C,
	0xFF0030,
	0xFF0024,
	0xFF0018,
	0xFF000C,
	0xFF0000,
	0xFF0C00,
	0xFF1800,
	0xFF2400,
	0xFF3000,
	0xFF3C00,
	0xFF4800,
	0xFF5400,
	0xFF6100,
	0xFF6D00,
	0xFF7900,
	0xFF8500,
	0xFF9100,
	0xFF9D00,
	0xFFAA00,
	0xFFB600,
	0xFFC200,
	0xFFCE00,
	0xFFDA00,
	0xFFE600,
	0xFFF200,
	0xFFFF00
};
	if (i == all->ite_max)
		all->img.clrline = 0x000000;
	else
		all->img.clrline = tab[i % 64];
}

void		frac_calc(t_frac *frac, double c_r, double c_i, int ite_max)
{
	frac->d_r = frac->z_r * frac->z_r;
	frac->d_i = frac->z_i * frac->z_i;
	while ((frac->d_r + frac->d_i) < 4 && frac->i < ite_max)
	{
		frac->z_i = (2 * frac->z_r * frac->z_i) + c_i;
		frac->z_r = frac->d_r - frac->d_i + c_r;
		frac->d_r = frac->z_r * frac->z_r;
		frac->d_i = frac->z_i * frac->z_i;
		frac->i++;
	}
}

void		frac_mandelbrot(t_all *all)
{
	t_frac	frac;

	frac.pt.x = 0;
	frac.x1 = -2.1;
	frac.y1 = -1.2;
	while (frac.pt.x < WIN_SZ_X)
	{
		frac.pt.y = 0;
		frac.c_r = ((frac.pt.x + all->off.x) / all->zoom) + frac.x1;
		frac.c_i = ((frac.pt.y + all->off.y) / all->zoom) + frac.y1;
		while (frac.pt.y < WIN_SZ_Y)
		{
			frac.z_r = frac.c_r;
			frac.z_i = frac.c_i;
			frac.c_i += 1 / all->zoom;
			frac.i = 0;
			frac_calc(&frac, frac.c_r, frac.c_i, all->ite_max);
			color_frac(frac.i, all);
			ft_put_pxl(all, &frac.pt);
			frac.pt.y++;
		}
		frac.pt.x++;
	}
}

void		frac_julia(t_all *all)
{
	t_frac	frac;

	frac.x1 = -1.4;
	frac.y1 = -1.2;
	frac.pt.x = 0;
	while (frac.pt.x < WIN_SZ_X)
	{
		frac.pt.y = 0;
		while (frac.pt.y < WIN_SZ_Y)
		{
			frac.z_r = (frac.pt.x + all->off.x) / all->zoom + frac.x1;
			frac.z_i = (frac.pt.y + all->off.y) / all->zoom + frac.y1;
			frac.i = 0;
			frac_calc(&frac, all->c_r, all->c_i, all->ite_max);
			color_frac(frac.i, all);
			ft_put_pxl(all, &frac.pt);
			frac.pt.y++;
		}
		frac.pt.x++;
	}
}

void		frac_douady(t_all *all)
{
	t_frac	frac;

	frac.x1 = -1.4;
	frac.y1 = -1.2;
	frac.c_r = -0.123;
	frac.c_i = 0.745;
	frac.pt.x = 0;
	while (frac.pt.x < WIN_SZ_X)
	{
		frac.pt.y = 0;
		while (frac.pt.y < WIN_SZ_Y)
		{
			frac.z_r = (frac.pt.x + all->off.x) / all->zoom + frac.x1;
			frac.z_i = (frac.pt.y + all->off.y) / all->zoom + frac.y1;
			frac.i = 0;
			frac_calc(&frac, frac.c_r, frac.c_i, all->ite_max);
			color_frac(frac.i, all);
			ft_put_pxl(all, &frac.pt);
			frac.pt.y++;
		}
		frac.pt.x++;
	}
}
