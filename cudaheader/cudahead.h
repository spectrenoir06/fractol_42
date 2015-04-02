/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cudahead.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoussau <antoine@doussaud.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 16:08:27 by aalliot           #+#    #+#             */
/*   Updated: 2015/02/03 16:08:30 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUDA_HEAD_H
# define CUDA_HEAD_H

#include "fractol.h"

# ifdef __cplusplus
extern "C"
# endif

void	call_mandelbrot(int *tab, double offx, double offy, double zoom, int ite_max, int winszx, int winszy);
void	call_julia(int *tab, double offx, double offy, double zoom, int ite_max, int winszx, int winszy, double c_i, double c_r);
void	call_douady(int *tab, double offx, double offy, double zoom, int ite_max, int winszx, int winszy);

# ifdef __APPLE__
#  define CALL_MANDELBROT call_mandelbrot(all->tab, all->off.x, all->off.y, all->zoom, all->ite_max, WIN_SZ_X, WIN_SZ_Y)
#  define CALL_JULIA call_julia(all->tab, all->off.x, all->off.y, all->zoom, all->ite_max, WIN_SZ_X, WIN_SZ_Y, all->c_i, all->c_r)
#  define CALL_DOUADY call_douady(all->tab, all->off.x, all->off.y, all->zoom, all->ite_max, WIN_SZ_X, WIN_SZ_Y)
# elif __linux
#  define CALL_MANDELBROT
#  define CALL_JULIA
#  define CALL_DOUADY
# endif

#endif
