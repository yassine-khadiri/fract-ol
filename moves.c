/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_mandelbrot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhadiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 19:47:01 by ykhadiri          #+#    #+#             */
/*   Updated: 2022/03/02 15:18:16 by ykhadiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_bool_val(t_fractol *data)
{
	if (data->julia_bool)
		data->julia_bool = 0;
	else
		data->julia_bool = 1;
}

void	reset(t_fractol *data)
{
	init_vals(data);
}

void	ft_moves(t_fractol *data, int key)
{
	if (key == 126)
		data->im_oregin += 0.1 * data->zoom;
	if (key == 124)
		data->re_oregin -= 0.1 * data->zoom;
	if (key == 125)
		data->im_oregin -= 0.1 * data->zoom;
	if (key == 123)
		data->re_oregin += 0.1 * data->zoom;
}

int	key_hook(int key, t_fractol *data)
{
	if (key == 126)
		ft_moves(data, key);
	if (key == 124)
		ft_moves(data, key);
	if (key == 125)
		ft_moves(data, key);
	if (key == 123)
		ft_moves(data, key);
	if (key == 24 || key == 35)
		data->max_iteration += 20;
	if ((key == 27 || key == 45) && data->max_iteration >= 100)
		data->max_iteration -= 20;
	if (key == 15)
		reset(data);
	if (key == 8)
		change_color(data);
	if (key == 53 || key == 12)
	{
		mlx_destroy_window(data->mlx, data->win);
		free(data);
		exit(0);
	}
	ft_draw(data);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_fractol *data)
{
	double	n_or;
	double	n_oi;
	double	afterx;
	double	aftery;

	n_or = ft_map(x, WIDTH, data->re_oregin - data->zoom,
			data->re_oregin + data->zoom);
	n_oi = ft_map(y, HEIGHT, data->im_oregin - data->zoom,
			data->im_oregin + data->zoom);
	if (button == 5)
		data->zoom /= 1.1;
	if (button == 4)
		data->zoom *= 1.1;
	if (button == 1 && data->julia)
		set_bool_val(data);
	afterx = ft_map(x, WIDTH, data->re_oregin - data->zoom,
			data->re_oregin + data->zoom);
	aftery = ft_map(y, HEIGHT, data->im_oregin - data->zoom,
			data->im_oregin + data->zoom);
	data->re_oregin += (n_or - afterx);
	data->im_oregin += (n_oi - aftery);
	ft_draw(data);
	return (0);
}
