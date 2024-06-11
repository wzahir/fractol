/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzahir <wzahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:31:16 by wzahir            #+#    #+#             */
/*   Updated: 2024/06/03 18:18:01 by wzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	check_cv_julia(t_fractal *fra)
{
	double	tmp;
	int		iter;

	fra->zr = ((fra->max - fra->min) * fra->x / WIDTH) + fra->min
		+ fra->offset_x;
	fra->zi = fra->max + (((fra->min - fra->max) * fra->y) / HEIGHT)
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
		fra->color = ((fra->shift.r % 256) << 16) | ((fra->shift.g
					% 256) << 8) | (fra->shift.b % 256);
		put_color_to_pixel(fra, fra->color, iter);
	}
}

void	draw_julia(t_fractal *fractal)
{
	fractal->x = 0.0;
	while (fractal->x < WIDTH)
	{
		fractal->y = 0.0;
		while (fractal->y < HEIGHT)
		{
			check_cv_julia(fractal);
			fractal->y++;
		}
		fractal->x++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
}
