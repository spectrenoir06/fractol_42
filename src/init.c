/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoussau <antoine@doussaud.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 20:10:41 by aalliot           #+#    #+#             */
/*   Updated: 2015/02/03 20:10:43 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		cartridge(t_all *all)
{
	mlx_string_put(all->env.mlx, all->env.win, (WIN_SZ_X / 2) - 165, 20, \
	0xFFC700, "                          FRACTOL                         ");
	mlx_string_put(all->env.mlx, all->env.win, (WIN_SZ_X / 2) - 165, 20, \
	0xFFC700, "+------------------------         -----------------------+");
	mlx_string_put(all->env.mlx, all->env.win, 10, 30, 0xFFC700, all->name);
	if (!all->cuda_frac)
		mlx_string_put(all->env.mlx, all->env.win, 10, 50, 0xFFC700,\
			"CUDA Parallel Computing Architecture : OFF");
	else
		mlx_string_put(all->env.mlx, all->env.win, 10, 50, 0xFFC700,\
			"CUDA Parallel Computing Architecture : ON");
	mlx_string_put(all->env.mlx, all->env.win, 10, 70, 0xFFC700,\
		"Number of iterations =");
	mlx_string_put(all->env.mlx, all->env.win, 150, 70, 0xFFC700,\
		ft_itoa(all->ite_max));
	mlx_string_put(all->env.mlx, all->env.win, 10, 90, 0xFFC700,\
		"Iteration +/- 200: a/d .");
	mlx_string_put(all->env.mlx, all->env.win, 10, 110, 0xFFC700,\
		"Navigation : Arrows .");
	mlx_string_put(all->env.mlx, all->env.win, 10, 130, 0xFFC700,\
		"Change color rainbow : c .");
	mlx_string_put(all->env.mlx, all->env.win, 10, 150, 0xFFC700,\
		"Zoom : Scroll Mouse .");
	mlx_string_put(all->env.mlx, all->env.win, 10, 170, 0xFFC700,\
		"Exit : esc .");
}

void		choose_frac(t_all *all)
{
	if (all->frac_no == 1)
	{
		!all->cuda_frac ? frac_mandelbrot(all) : cuda_mandelbrot(all);
		ft_strcpy(all->name, "Fractal name: Mandelbrot");
	}
	else if (all->frac_no == 2)
	{
		!all->cuda_frac ? frac_julia(all) : cuda_julia(all);
		ft_strcpy(all->name, "Fractal name: Julia");
	}
	else if (all->frac_no == 3)
	{
		!all->cuda_frac ? frac_douady(all) : cuda_douady(all);
		ft_strcpy(all->name, "Fractal name: Douady Rabbit");
	}
}


void GiveRainbowColor(double position,unsigned char c[])
{
  /* if position > 1 then we have repetition of colors it maybe useful    */

	if (position>1.0)
	{
		if (position-(int)position==0.0)
			position=1.0;
		else
			position=position-(int)position;
	}

	unsigned char nmax=6; /* number of color segments */
	double m=nmax* position;

	int n=(int)m; // integer of m

	double f=m-n;  // fraction of m
	unsigned char t=(int)(f*255);

	if (n == 0)
	{
		c[0] = 255;
		c[1] = t;
		c[2] = 0;
	}
	else if (n == 1)
	{
		c[0] = 255 - t;
		c[1] = 255;
		c[2] = 0;
	}
	else if (n == 2)
	{
		c[0] = 0;
		c[1] = 255;
		c[2] = t;
	}
	else if (n == 3)
	{
		c[0] = 0;
		c[1] = 255 - t;
		c[2] = 255;
	}
	else if (n == 4)
	{
		c[0] = t;
		c[1] = 0;
		c[2] = 255;
	}
	else if (n == 5)
	{
		c[0] = 255;
		c[1] = 0;
		c[2] = 255 - t;
	}
	else
	{
		c[0] = 255;
		c[1] = 0;
		c[2] = 0;
	}
}

#include <stdio.h>

void		all_init(t_all *all)
{
	if (!(all->env.mlx = mlx_init()))
	{
		ft_putendl_fd("You won't fuck me like that!!", 2);
		exit(2);
	}
	all->env.win = mlx_new_window(all->env.mlx, WIN_SZ_X, WIN_SZ_Y, "Fractol");
	all->img.img = mlx_new_image(all->env.mlx, WIN_SZ_X, WIN_SZ_Y);
	all->img.data = mlx_get_data_addr(all->img.img, &all->img.bpp,
	&all->img.sizeline, &all->img.endian);
	all->img.clrline = 0xFFC700;
	all->zoom = 300;
	all->off.x = -100;
	all->off.y = -100;
	all->ite_max = 200;
	all->re = 1;
	all->f = 1;
	all->filter = -1;
	all->color = 1;
	all->inc = all->img.bpp / 8;

	int dl = 0;
	unsigned int c;
	all->pallette_nb = NB_COLOR;
	all->pallette = malloc(sizeof(int) * all->pallette_nb);
	for (dl = 0; dl <= all->pallette_nb; dl++)
	{
		GiveRainbowColor(dl / (double)all->pallette_nb, (unsigned char *)&c);
		//printf("%x\n", c);
		all->pallette[dl] = c;
	}



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
