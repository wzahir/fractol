/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzahir <wzahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:29:09 by wzahir            #+#    #+#             */
/*   Updated: 2024/06/03 17:34:05 by wzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mose_code(int code, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (code == 4)
	{
		fractal->zoom *= 1.1;
		fractal->max *= 1.1;
		fractal->min *= 1.1;
	}
	else if (code == 5)
	{
		fractal->zoom /= 1.1;
		fractal->max /= 1.1;
		fractal->min /= 1.1;
	}
	draw_fractal(fractal);
	return (0);
}

int	ft_close(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img);
	mlx_destroy_window(fractal->mlx, fractal->win);
	exit(0);
}

void	move(t_fractal *fractal, int code)
{
	if (code == 123)
		fractal->offset_x += (0.5 * fractal->zoom);
	if (code == 124)
		fractal->offset_x -= (0.5 * fractal->zoom);
	if (code == 125)
		fractal->offset_y += (0.5 * fractal->zoom);
	if (code == 126)
		fractal->offset_y -= (0.5 * fractal->zoom);
}

void	change_color(t_fractal *fractal, int code)
{
	if (code == 83)
	{
		fractal->shift.r = 10;
		fractal->shift.g = 0;
		fractal->shift.b = 0;
	}
	if (code == 84)
	{
		fractal->shift.r = 0;
		fractal->shift.g = 0;
		fractal->shift.b = 20;
	}
	if (code == 86)
	{
		fractal->shift.r = 0;
		fractal->shift.g = 10;
		fractal->shift.b = 0;
	}
	if (code == 87)
	{
		fractal->shift.r += 2;
		fractal->shift.g += 2;
		fractal->shift.b += 2;
	}
}

int	keycode(int code, t_fractal *fractal)
{
	if (code == 53)
		ft_close(fractal);
	if (code == 123 || code == 124 || code == 125 || code == 126)
		move(fractal, code);
	if (code == 83 || code == 84 || code == 86 || code == 87)
		change_color(fractal, code);
	draw_fractal(fractal);
	return (0);
}
