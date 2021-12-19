/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khestia <khestia@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 10:46:37 by khestia           #+#    #+#             */
/*   Updated: 2021/12/15 13:45:39 by khestia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include "../inc/keys.h"

void	ft_change(t_fractol *fr, int key)
{
	if (key == PLUS)
	{
		fr->c_r += 0.01;
		fr->c_i -= 0.01;
	}
	if (key == MINUS)
	{
		fr->c_r -= 0.01;
		fr->c_i += 0.01;
	}
}

int	ft_key_press(int key, t_fractol *fr)
{
	if (key == LEFT_KEY)
		fr->x_center -= 10 / fr->zoom;
	if (key == UP_KEY)
		fr->y_center -= 10 / fr->zoom;
	if (key == RIGHT_KEY)
		fr->x_center += 10 / fr->zoom;
	if (key == DOWN_KEY)
		fr->y_center += 10 / fr->zoom;
	if (key == SHIFT_L || key == SHIFT_R)
	{
		if (fr->color_change == 2)
			fr->color_change = -1;
		fr->color_change++;
	}
	if (key == ESC_KEY)
		ft_exit(fr);
	if ((key == PLUS || key == MINUS)
		&& (ft_strncmp(fr->name, "Julia", ft_strlen(fr->name))
			== 0 && ft_strlen(fr->name) == 5))
		ft_change(fr, key);
	ft_what_fractal2(fr);
	return (0);
}

void	ft_exit(t_fractol *fr)
{
	if (fr->mlx && fr->mlx_win)
		mlx_destroy_window(fr->mlx, fr->mlx_win);
	if (fr->mlx && fr->img)
		mlx_destroy_image(fr->mlx, fr->img);
	exit(0);
}
