/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzahir <wzahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 13:15:05 by wzahir            #+#    #+#             */
/*   Updated: 2024/06/01 22:59:01 by wzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_color_to_pixel(t_fractal *fractal, unsigned int color,
		int iteration)
{
	unsigned int	*addr;

	addr = fractal->addr_pixel + ((int)fractal->y * fractal->size_line)
		+ ((int)fractal->x * (fractal->bpp / 8));
	*addr = color * iteration;
}

void	check_cv_mandelbrot(t_fractal *fra)
{
	double	tmp;
	int		iter;

	fra->zr = 0.0;
	fra->zi = 0.0;
	fra->cr = ((fra->max - fra->min) * fra->x / WIDTH) + fra->min
		+ fra->offset_x;
	fra->ci = fra->max + (((fra->min - fra->max) * fra->y) / HEIGHT)
		+ fra->offset_y;
	iter = 0;
	while (fra->zr * fra->zr + fra->zi * fra->zi < 4 && iter < fra->max_iter)
	{
		tmp = fra->zr * fra->zr - fra->zi * fra->zi + fra->cr;
		fra->zi = 2 * fra->zr * fra->zi + fra->ci;
		fra->zr = tmp;
		iter++;
	}
	if (iter == fra->max_iter)
		put_color_to_pixel(fra, BLACK, iter);
	else
	{
		fra->color = (((fra->shift.r % 256) << 16) | ((fra->shift.g
						% 256) << 8) | (fra->shift.b % 256));
		put_color_to_pixel(fra, fra->color, iter);
	}
}

void	draw_mandelbrot(t_fractal *fractal)
{
	fractal->x = 0.0;
	while (fractal->x < WIDTH)
	{
		fractal->y = 0.0;
		while (fractal->y < HEIGHT)
		{
			check_cv_mandelbrot(fractal);
			fractal->y++;
		}
		fractal->x++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
}
