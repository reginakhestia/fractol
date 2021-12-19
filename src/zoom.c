/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khestia <khestia@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 20:24:19 by khestia           #+#    #+#             */
/*   Updated: 2021/12/11 17:19:40 by khestia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include "../inc/keys.h"

int	ft_zoom(int button, int x, int y, t_fractol *fr)
{
	if (button == SCROLL_UP)
	{
		x = (x - 400);
		y = (y - 400);
		fr->x_center = fr->x_center + (x - x / 1.3) / fr->zoom;
		fr->y_center = fr->y_center + (y - y / 1.3) / fr->zoom;
		fr->zoom *= 1.3;
		fr->scale *= 1.3;
		fr->iter += 1;
	}
	if (button == SCROLL_DOWN)
	{
		x = (x - 400);
		y = (y - 400);
		fr->x_center = fr->x_center - (x - x / 1.3) / fr->zoom;
		fr->y_center = fr->y_center - (y - y / 1.3) / fr->zoom;
		fr->zoom /= 1.3;
		fr->scale /= 1.3;
		fr->iter -= 1;
	}
	ft_what_fractal2(fr);
	return (0);
}
