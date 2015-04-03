/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoussau <antoine@doussaud.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 20:10:41 by adoussau          #+#    #+#             */
/*   Updated: 2015/02/03 20:10:43 by adoussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		cartridge(t_all *all)
{
	/*
	int x = 0;
	int y = 0;

	while (x < WIN_SZ_X)
	{
		y = 0;
		while (y <= 65)
		{
			mlx_pixel_put(all->env.mlx, all->env.win, x, y, 0);
			y++;
		}
		x++;
	}*/

	mlx_string_put(all->env.mlx, all->env.win, 10, 15, 0xFFC700, "Fractal:");
	mlx_string_put(all->env.mlx, all->env.win, 90, 15, 0xFFC700, all->name);
	mlx_string_put(all->env.mlx, all->env.win, 10, 30, 0xFFC700, "CUDA:");
	mlx_string_put(all->env.mlx, all->env.win, 90, 30, (all->cuda_frac ? 0x00FF00 : 0XFF0000), (all->cuda_frac ? "ON" : "OFF"));
	mlx_string_put(all->env.mlx, all->env.win, 10, 45, 0xFFC700, "Iterations:");
	mlx_string_put(all->env.mlx, all->env.win, 90, 45, 0xFFC700,
		ft_itoa(all->ite_max));
	mlx_string_put(all->env.mlx, all->env.win, 10, 60, 0xFFC700,
		"Zoom:");
	mlx_string_put(all->env.mlx, all->env.win, 90, 60, 0xFFC700,
		ft_itoa((int)all->zoom / 3));
	mlx_string_put(all->env.mlx, all->env.win, 110, 60, 0xFFC700,
		"%");
	mlx_string_put(all->env.mlx, all->env.win, 500, 15, 0xFFC700,
		"Iteration +/- : A/D");
	mlx_string_put(all->env.mlx, all->env.win, 500, 30, 0xFFC700,
		"Navigation    : Arrows");
	mlx_string_put(all->env.mlx, all->env.win, 500, 45, 0xFFC700,
		"Zoom          : Scroll Mouse");
	mlx_string_put(all->env.mlx, all->env.win, 500, 60, 0xFFC700,
		"Exit          : ESC");
}

void		choose_frac(t_all *all)
{
	if (all->frac_no == 1)
	{
		!all->cuda_frac ? frac_mandelbrot(all) : cuda_mandelbrot(all);
		ft_strcpy(all->name, "Mandelbrot");
	}
	else if (all->frac_no == 2)
	{
		!all->cuda_frac ? frac_julia(all) : cuda_julia(all);
		ft_strcpy(all->name, "Julia");
	}
	else if (all->frac_no == 3)
	{
		!all->cuda_frac ? frac_douady(all) : cuda_douady(all);
		ft_strcpy(all->name, "Douady Rabbit");
	}
}

int			color(double position)
{
	unsigned char	t;

	t = (int)(((double)((6 * position) - (int)(6 * position))) * 255);
	if ((int)(6 * position) == 0)
		return ((t << 8) | 0xFF);
	else if ((int)(6 * position) == 1)
		return (0xFF00 | (0xFF - t));
	else if ((int)(6 * position) == 2)
		return ((t << 16) | 0xFF00);
	else if ((int)(6 * position) == 3)
		return (((0xFF - t) << 8) | 0xFF0000);
	else if ((int)(6 * position) == 4)
		return (0xFF0000 | t);
	else if ((int)(6 * position) == 5)
		return (((255 - t) << 16) | 0xFF);
	else
		return (0xFF);
}

void		all_init(t_all *all)
{
	int				i;

	if (!(all->env.mlx = mlx_init()))
	{
		ft_putendl_fd("Can't display (No X server)", 2);
		exit(2);
	}
	all->env.win = mlx_new_window(all->env.mlx, WIN_SZ_X, WIN_SZ_Y, "Fractol");
	all->img.img = mlx_new_image(all->env.mlx, WIN_SZ_X, WIN_SZ_Y);
	all->img.data = mlx_get_data_addr(all->img.img, &all->img.bpp,
	&all->img.sizeline, &all->img.endian);
	all->img.clrline = 0xFFC700;
	all->zoom = 300;
	all->off.x = -100;
	all->off.y = -200;
	all->ite_max = 200;
	all->re = 1;
	all->f = 1;
	all->filter = -1;
	all->color = 1;
	all->inc = all->img.bpp / 8;
	i = 0;
	while (i++ <= NB_COLOR)
		all->pallette[i - 1] = color((i - 1) / (double)NB_COLOR);
}

void		frac_init(t_all *all, int argc, char *argv[])
{
	if (argc != 3)
		ft_usage();
	else
	{
		if (ft_strcmp(argv[1], "-cpu") == 0)
			all->cuda_frac = 0;
		else if (ft_strcmp(argv[1], "-gpu") == 0)
			all->cuda_frac = 1;
		else
			ft_usage();
		if (ft_strcmp(argv[2], "mandelbrot") == 0)
			all->frac_no = 1;
		else if (ft_strcmp(argv[2], "julia") == 0)
			all->frac_no = 2;
		else if (ft_strcmp(argv[2], "douady") == 0)
			all->frac_no = 3;
		else
			ft_usage();
		all_init(all);
	}
}
