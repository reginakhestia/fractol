/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khestia <khestia@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:32:01 by khestia           #+#    #+#             */
/*   Updated: 2021/12/15 13:42:01 by khestia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include "../inc/keys.h"

void	ft_what_fractal2(t_fractol *fr)
{
	if (ft_strncmp(fr->name, "Julia", ft_strlen(fr->name)) == 0
		&& ft_strlen(fr->name) == 5)
		ft_draw_julia(fr);
	else if (ft_strncmp(fr->name, "Mandelbrot", ft_strlen(fr->name)) == 0
		&& ft_strlen(fr->name) == 10)
		ft_draw_mandelbrot(fr);
	else if (ft_strncmp(fr->name, "BurningShip", ft_strlen(fr->name)) == 0
		&& ft_strlen(fr->name) == 11)
		ft_draw_burning(fr);
	else
		ft_exit(fr);
}

double	ft_change_color(t_fractol *fr)
{
	double	r;
	double	g;
	double	b;

	if (fr->color_change == 0)
	{
		r = fr->fact_iter * 665456;
		g = fr->fact_iter * 3350;
		b = fr->fact_iter * 971900;
	}
	if (fr->color_change == 1)
	{
		r = fr->fact_iter * 159;
		g = fr->fact_iter * 879;
		b = fr->fact_iter * 10022;
	}
	if (fr->color_change == 2)
	{
		r = (fr->fact_iter + 25) * 280;
		g = (fr->fact_iter + 25) * 767;
		b = (fr->fact_iter + 25) * 900857;
	}
	return (r + g + b);
}

void	ft_pixel_color(double i, t_fractol *fr)
{
	double	color;

	color = ft_change_color(fr);
	if (i == -1)
		ft_pixel_put(fr, 000000000);
	else
		ft_pixel_put(fr, color);
}

void	ft_pixel_put(t_fractol *fr, int color)
{
	char	*s;

	s = fr->addres + (int)((fr->y + 400) * fr->line_length
			+ (fr->x + 400) * (fr->bpp / 8));
	*(unsigned int *)s = color;
}
