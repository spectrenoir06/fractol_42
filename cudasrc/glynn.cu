/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.cu                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoussau <antoine@doussaud.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 16:08:27 by adoussau          #+#    #+#             */
/*   Updated: 2015/02/03 16:08:30 by adoussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <cuda.h>
#include <stdio.h>
# define WIN_SZ_X 1024
# define WIN_SZ_Y 1024

# define TYPE double

__global__ void		glynn(int	*d_tab, double offx, double offy, double zoom, int ite_max, int winszx, int winszy)
{
	float	temp = 0;

	int row = blockIdx.y * blockDim.y + threadIdx.y;
	int col = blockIdx.x * blockDim.x + threadIdx.x;
	int index = row * winszx + col;
	if(col >= winszx || row >= winszy)
		return;
	TYPE z_r = (((double)col + offx) / zoom) + -2.1;
	TYPE z_i = (((double)row + offy) / zoom) + -1.2;
	unsigned int i = 0;
	while(sqrt(z_r * z_r + z_i * z_i) < 1 && i < it_max)
	{
		temp = z_r;
		z_r = sqrt((z_r * z_r - z_i * z_i) * (z_r * z_r - z_i * z_i)) + c_r;
		z_i = sqrt((2 * z_i * temp)*(2 * z_i * temp)) + c_i;
		i++;
	}
	d_tab[index] = i;
}

extern "C" void			call_glynn(int *tab, double offx, double offy, double zoom, int ite_max, int winszx, int winszy)
{
	int		*d_tab = NULL;
	int		size = 0;
	dim3	block_size(16, 16);
	dim3	grid_size(WIN_SZ_X / block_size.x, WIN_SZ_Y / block_size.y);

	size = WIN_SZ_Y * WIN_SZ_X * sizeof(int);
	cudaMalloc((void **)&d_tab, size);
	glynn<<<grid_size,block_size>>>(d_tab, offx, offy, zoom, ite_max, winszx, winszy);

	cudaMemcpy(tab, d_tab, size, cudaMemcpyDeviceToHost);
	cudaFree(d_tab);
}
