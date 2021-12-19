/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khestia <khestia@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:47:04 by khestia           #+#    #+#             */
/*   Updated: 2021/12/14 23:16:52 by khestia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include "../inc/keys.h"

void	*ft_init_struct_julia(t_fractol *fr)
{
	fr->p = WIN_SIZE / 2;
	fr->x = -fr->p;
	fr->y = -fr->p;
	fr->iter = 50;
	fr->factor = 1.5;
	fr->scale = (fr->p / fr->factor);
	fr->fact_iter = 0;
	fr->zoom = 1;
	fr->x_center = 0;
	fr->y_center = 0;
	fr->color_change = 0;
	return (fr);
}

double	ft_calculate_julia(t_fractol *fr)
{
	double	a;
	double	b;
	double	tmp;

	fr->fact_iter = 0;
	a = (fr->x + fr->x_center * fr->zoom) / fr->scale;
	b = (fr->y + fr->y_center * fr->zoom) / fr->scale;
	while (fr->fact_iter < fr->iter)
	{
		tmp = a;
		a = (a * a) - (b * b);
		b = tmp * b * 2;
		a += fr->c_r;
		b += fr->c_i;
		tmp = sqrt((a * a) + (b * b));
		if (tmp > 2)
			break ;
		fr->fact_iter++;
	}
	return (tmp);
}

void	ft_draw_julia(t_fractol *fr)
{
	fr->x = -fr->p;
	while (fr->x <= fr->p)
	{
		fr->y = -fr->p;
		while (fr->y <= fr->p)
		{
			if (ft_calculate_julia(fr) <= 2)
				ft_pixel_color(-1, fr);
			else
				ft_pixel_color(fr->fact_iter, fr);
			fr->y++;
		}
		fr->x++;
	}
	mlx_put_image_to_window(fr->mlx, fr->mlx_win, fr->img, 0, 0);
}
