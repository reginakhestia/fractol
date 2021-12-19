/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_double.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khestia <khestia@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:31:52 by khestia           #+#    #+#             */
/*   Updated: 2021/12/15 00:09:41 by khestia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include "../inc/keys.h"

void	ft_is_num(char c, t_fractol *fr)
{
	if (!(c >= '0' && c <= '9'))
	{
		printf("try this: ./fractol Julia (r i) / Mandelbrot / BurningShip\n");
		ft_exit(fr);
	}
}

double	ft_znak(char c)
{
	if (c == '-')
		return (-1);
	if (c == '+')
		return (1);
	else
		return (0);
}

double	continue_atoi(char *s, int i, double n, t_fractol *fr)
{
	double	c;

	c = 0.1;
	while (s[i])
	{
		ft_is_num(s[i], fr);
		n = n + (s[i] - '0') * c;
		c *= 0.1;
		i++;
	}
	return (n);
}

double	ft_atoi_double(char *s, t_fractol *fr)
{
	int		i;
	double	n;
	double	z;

	i = 0;
	n = 0;
	z = ft_znak(s[0]);
	if (z != 0)
		i++;
	if (z == 0)
		z = 1;
	while (s[i] && s[i] != '.')
	{
		ft_is_num(s[i], fr);
		n = n * 10 + (s[i] - '0');
		i++;
	}
	if (!s[i])
		return (n * z);
	i++;
	n = continue_atoi(s, i, n, fr);
	return (n * z);
}
