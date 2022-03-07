/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhadiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:31:09 by ykhadiri          #+#    #+#             */
/*   Updated: 2022/03/04 18:32:22 by ykhadiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_color(t_fractol *data)
{
	if (data->color_id == 8)
	{
		data->color_id = -1;
		data->color = 0xfff600;
	}
	else if (data->color_id == 0)
		data->color = 0xff0801;
	else if (data->color_id == 1)
		data->color = 0xfff600;
	else if (data->color_id == 2)
		data->color = 0x18ff00;
	else if (data->color_id == 3)
		data->color = 0xf4f4f5;
	else if (data->color_id == 4)
		data->color = 0xb0ffd9;
	else if (data->color_id == 5)
		data->color = 0xffffd9;
	else if (data->color_id == 6)
		data->color = 0xFFFCA7;
	else if (data->color_id == 7)
		data->color = 0xf1f1e1;
	data->color_id++;
}

void	ft_calc(t_fractol *data)
{
	data->z_r = pow(data->a, 2) - pow(data->b, 2);
	data->z_i = 2 * data->a * data->b;
	if (data->burning_ship)
		data->z_i = fabs(2 * data->a * data->b);
	data->a = data->z_r + data->c_r;
	data->b = data->z_i + data->c_i;
}

int	key_hook_val(int x, int y, t_fractol *data)
{
	if ((x >= 0 && x <= 700) && (y >= 0 && y <= 700) && !data->julia_bool)
	{
		data->c_r = ft_map(x, WIDTH, data->re_oregin - data->zoom,
				data->re_oregin + data->zoom);
		data->c_i = ft_map(y, HEIGHT, data->im_oregin - data->zoom,
				data->im_oregin + data->zoom);
		ft_draw(data);
	}
	return (0);
}
