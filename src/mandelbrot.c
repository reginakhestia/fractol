/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khestia <khestia@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:51:16 by khestia           #+#    #+#             */
/*   Updated: 2021/12/14 18:30:49 by khestia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include "../inc/keys.h"

void	*ft_init_struct_mandelbrot(t_fractol *fr)
{
	fr->p = WIN_SIZE / 2;
	fr->x = -fr->p;
	fr->y = -fr->p;
	fr->c_r = 0;
	fr->c_i = 0;
	fr->iter = 50;
	fr->factor = 2;
	fr->scale = (fr->p / fr->factor);
	fr->fact_iter = 0;
	fr->zoom = 1;
	fr->x_center = 0;
	fr->y_center = 0;
	fr->color_change = 0;
	return (fr);
}

double	ft_calculate_mandelbrot(t_fractol *fr)
{
	double	a;
	double	b;
	double	tmp;

	fr->fact_iter = 0;
	a = (fr->x + fr->x_center * fr->zoom) / fr->scale;
	b = (fr->y + fr->y_center * fr->zoom) / fr->scale;
	while (fr->fact_iter < fr->iter)
	{
		tmp = fr->c_r;
		fr->c_r = (fr->c_r * fr->c_r) - (fr->c_i * fr->c_i);
		fr->c_i = tmp * fr->c_i * 2;
		fr->c_r += a;
		fr->c_i += b;
		tmp = sqrt((fr->c_r * fr->c_r) + (fr->c_i * fr->c_i));
		if (tmp > 2)
			break ;
		fr->fact_iter++;
	}
	return (tmp);
}

void	ft_draw_mandelbrot(t_fractol *fr)
{
	fr->x = -fr->p;
	while (fr->x <= fr->p)
	{
		fr->y = -fr->p;
		while (fr->y <= fr->p)
		{
			fr->c_r = 0;
			fr->c_i = 0;
			if (ft_calculate_mandelbrot(fr) <= 2)
				ft_pixel_color(-1, fr);
			else
				ft_pixel_color(fr->fact_iter, fr);
			fr->y++;
		}
		fr->x++;
	}
	mlx_put_image_to_window(fr->mlx, fr->mlx_win, fr->img, 0, 0);
}
