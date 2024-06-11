/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzahir <wzahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:53:38 by wzahir            #+#    #+#             */
/*   Updated: 2024/06/03 17:27:19 by wzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init(t_fractal *fractal)
{
	fractal->max = 2;
	fractal->min = -2;
	fractal->offset_x = 0;
	fractal->offset_y = 0;
	fractal->zoom = 1;
	fractal->max_iter = 100;
	fractal->shift.r = 10;
	fractal->shift.g = 0;
	fractal->shift.b = 10;
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
	{
		free(fractal->mlx);
		exit(1);
	}
	fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, "My window");
	if (!fractal->win)
	{
		mlx_destroy_window(fractal->mlx, fractal->win);
		exit(1);
	}
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	fractal->addr_pixel = mlx_get_data_addr(fractal->img, &fractal->bpp,
			&fractal->size_line, &fractal->endian);
}

void	draw_fractal(t_fractal *fractal)
{
	mlx_clear_window(fractal->mlx, fractal->win);
	if (!ft_strncmp(fractal->name, "mandelbrot", 11))
		draw_mandelbrot(fractal);
	else
		draw_julia(fractal);
}
