/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzahir <wzahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:59:49 by wzahir            #+#    #+#             */
/*   Updated: 2024/06/02 20:56:29 by wzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	init_var(t_var *var)
{
	var->nb = 0;
	var->signe = 1;
	var->i = 0;
	var->k = 0;
}

double	ft_atof(char *str)
{
	t_var	var;

	init_var(&var);
	while ((str[var.i] >= 9 && str[var.i] <= 13) || str[var.i] == ' ')
		var.i++;
	if (str[var.i] == '+' || str[var.i] == '-')
	{
		if (str[var.i] == '-')
			var.signe = -1;
		var.i++;
	}
	while (str[var.i] >= 48 && str[var.i] <= 57)
		var.nb = var.nb * 10 + (str[var.i++] - 48);
	if (str[var.i] == '.')
	{
		var.i++;
		while (str[var.i] >= 48 && str[var.i] <= 57)
		{
			var.nb = var.nb * 10 + (str[var.i++] - 48);
			var.k++;
		}
		while (var.k-- > 0)
			var.nb = var.nb / 10;
	}
	return (var.nb * var.signe);
}
