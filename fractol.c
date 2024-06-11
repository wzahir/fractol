/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzahir <wzahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:51:00 by wzahir            #+#    #+#             */
/*   Updated: 2024/06/03 17:04:10 by wzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	valid_arg(int ac, char **av)
{
	if (!((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 11)) || (ac == 4
				&& !ft_strncmp(av[1], "julia", 6) && (is_valid(av[2])
					&& is_valid(av[3])))))
	{
		ft_putstr("invalid input must be :\n");
		ft_putstr("for mandelbrot : ./fractol mandelbrot\n");
		ft_putstr("for julia : ./fractol julia");
		ft_putstr(" <float c_real> <float c_imag>\n");
		exit(1);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if (valid_arg(ac, av))
	{
		fractal.name = av[1];
		init(&fractal);
		if (!ft_strncmp(fractal.name, "julia", 6))
		{
			fractal.cr = ft_atof(av[2]);
			fractal.ci = ft_atof(av[3]);
		}
		draw_fractal(&fractal);
		mlx_key_hook(fractal.win, keycode, &fractal);
		mlx_mouse_hook(fractal.win, mose_code, &fractal);
		mlx_hook(fractal.win, 17, 0, ft_close, &fractal);
		mlx_loop(fractal.mlx);
	}
	return (0);
}
