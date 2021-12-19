/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khestia <khestia@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 20:23:45 by khestia           #+#    #+#             */
/*   Updated: 2021/12/14 22:40:21 by khestia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_fractol
{
	char	*name;
	void	*mlx;
	void	*mlx_win;
	void	*img;
	void	*addres;
	int		line_length;
	int		endian;
	int		bpp;
	double	p;
	double	scale;
	double	x;
	double	y;
	double	c_r;
	double	c_i;
	double	iter;
	double	fact_iter;
	double	factor;
	double	zoom;
	double	x_center;
	double	y_center;
	double	color_change;
}	t_fractol;

int		ft_zoom(int button, int x, int y, t_fractol *fr);
void	ft_draw_julia(t_fractol *fractol);
void	ft_pixel_color(double i, t_fractol *fr);
int		ft_key_press(int key, t_fractol *fr);
void	ft_pixel_put(t_fractol *fr, int color);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlen(const char *s);
void	ft_what_fractal(t_fractol *fr);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_exit(t_fractol *fr);
void	*ft_init_struct_julia(t_fractol *fr);
void	ft_draw_mandelbrot(t_fractol *fr);
void	*ft_init_struct_mandelbrot(t_fractol *fr);
void	ft_what_fractal2(t_fractol *fr);
void	ft_draw_burning(t_fractol *fr);
void	*ft_init_struct_burning(t_fractol *fr);
void	ft_animation(t_fractol *fr);
double	ft_atoi_double(char *s, t_fractol *fr);

#endif
