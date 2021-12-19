/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khestia <khestia@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:07:45 by khestia           #+#    #+#             */
/*   Updated: 2021/12/15 13:46:43 by khestia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include "../inc/keys.h"

void	ft_init_window(t_fractol *fr)
{
	fr->mlx = mlx_init();
	fr->mlx_win = mlx_new_window(fr->mlx, WIN_SIZE, WIN_SIZE, "Fractol");
	fr->img = mlx_new_image(fr->mlx, WIN_SIZE, WIN_SIZE);
	fr->addres = mlx_get_data_addr(fr->img, &fr->bpp, &fr->line_length,
			&fr->endian);
}

void	ft_what_fractal(t_fractol *fr)
{
	if (ft_strncmp(fr->name, "Julia", ft_strlen(fr->name)) == 0
		&& ft_strlen(fr->name) == 5)
	{
		ft_init_struct_julia(fr);
		ft_draw_julia(fr);
	}
	else if (ft_strncmp(fr->name, "Mandelbrot", ft_strlen(fr->name)) == 0
		&& ft_strlen(fr->name) == 10)
	{
		ft_init_struct_mandelbrot(fr);
		ft_draw_mandelbrot(fr);
	}
	else if (ft_strncmp(fr->name, "BurningShip", ft_strlen(fr->name)) == 0
		&& ft_strlen(fr->name) == 11)
	{
		ft_init_struct_burning(fr);
		ft_draw_burning(fr);
	}
	else
	{
		printf("try this: ./fractol Julia (r i) / Mandelbrot / BurningShip\n");
		ft_exit(fr);
	}
}

void	ft_valid(t_fractol *fr, int argv, char **argc)
{
	if (ft_strncmp(fr->name, "Julia", ft_strlen(fr->name)) == 0
		&& ft_strlen(fr->name) == 5 && argv == 2)
	{
		fr->c_r = -0.74543;
		fr->c_i = 0.11301;
	}
	if (argv == 4)
	{
		if (ft_strncmp(fr->name, "Julia", ft_strlen(fr->name)) == 0
			&& ft_strlen(fr->name) == 5)
		{
			fr->c_r = ft_atoi_double(argc[2], fr);
			fr->c_i = ft_atoi_double(argc[3], fr);
		}
		else
		{
			printf("try this: ./fractol Julia (r i)/ Mandelbrot/ BurningShip\n");
			ft_exit(fr);
		}
	}
}

int	main(int argv, char **argc)
{
	t_fractol	*fr;

	if (argv < 2 || argv > 4 || argv == 3)
	{
		printf("try this: ./fractol Julia (r i) / Mandelbrot / BurningShip\n");
		return (0);
	}
	fr = (t_fractol *)malloc(sizeof(t_fractol));
	if (!fr)
		return (0);
	fr->name = (char *)malloc(sizeof(char) * (ft_strlen(argc[1]) + 1));
	if (!fr->name)
		ft_exit(fr);
	fr->name = ft_memmove(fr->name, argc[1], ft_strlen(argc[1]));
	ft_valid(fr, argv, argc);
	ft_init_window(fr);
	ft_what_fractal(fr);
	mlx_key_hook(fr->mlx_win, ft_key_press, fr);
	mlx_mouse_hook(fr->mlx_win, ft_zoom, fr);
	mlx_loop(fr->mlx);
}
