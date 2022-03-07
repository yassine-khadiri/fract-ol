/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhadiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 19:40:18 by ykhadiri          #+#    #+#             */
/*   Updated: 2022/03/02 15:19:36 by ykhadiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_vals(t_fractol *data)
{
	data->re_oregin = 0;
	data->im_oregin = 0;
	data->zoom = 2;
	data->max_iteration = 100;
	data->c_r = 0.285;
	data->c_i = 0;
	data->color = 0xf6ff02;
}

void	ft_draw(t_fractol *data)
{
	mlx_clear_window(data->mlx, data->win);
	data->y = 0;
	while (data->y < HEIGHT)
	{
		data->x = 0;
		while (data->x < WIDTH)
		{
			set_mapped_values(data);
			data->iteration = 0;
			data->new_color = 0;
			while (data->iteration < data->max_iteration)
			{
				ft_calc(data);
				data->iteration++;
				if (pow(data->a, 2) + pow(data->b, 2) > 4)
					break ;
			}
			if (data->iteration < data->max_iteration)
				data->new_color = data->color * data->iteration;
			my_mlx_pixel_put(data, data->x, data->y, data->new_color);
			data->x++;
		}
		data->y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}

void	launch(t_fractol *data)
{
	init_vals(data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "fractol");
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img,
			&data->img.bits_per_pixel, &data->img.line_length,
			&data->img.endian);
	ft_draw(data);
	mlx_hook(data->win, 2, 0, key_hook, data);
	mlx_hook(data->win, 17, 0, win_destroy, data);
	mlx_mouse_hook(data->win, mouse_hook, data);
	if (data->julia)
		mlx_hook(data->win, 6, 0, key_hook_val, data);
	mlx_loop(data->mlx);
}
