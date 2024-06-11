/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzahir <wzahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:49:38 by wzahir            #+#    #+#             */
/*   Updated: 2024/06/01 22:48:47 by wzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800
# define BLACK 0x000000

typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_color;

typedef struct s_fractal
{
	void			*mlx;
	void			*win;
	char			*name;
	void			*img;
	void			*addr_pixel;
	int				bpp;
	int				size_line;
	int				endian;
	double			x;
	double			y;
	double			cr;
	double			ci;
	double			zr;
	double			zi;
	double			max;
	double			min;
	int				max_iter;
	double			zoom;
	double			offset_x;
	double			offset_y;
	t_color			shift;
	unsigned int	color;
}					t_fractal;

typedef struct s_var
{
	int				i;
	double			nb;
	int				signe;
	int				k;
}					t_var;

void				init(t_fractal *fractal);
void				draw_fractal(t_fractal *fractal);
void				draw_mandelbrot(t_fractal *fractal);
void				draw_julia(t_fractal *fractal);
void				put_color_to_pixel(t_fractal *fractal, unsigned int color,
						int iteration);
int					keycode(int code, t_fractal *fractal);
int					ft_close(t_fractal *fractal);
int					mose_code(int code, int x, int y, t_fractal *fractal);
int					ft_strncmp(const char *s1, const char *s2, int n);
double				ft_atof(char *str);
void				ft_putstr(char *str);
int					is_valid(char *str);

#endif