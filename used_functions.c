/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   used_commun_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhadiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:36:39 by ykhadiri          #+#    #+#             */
/*   Updated: 2022/03/03 18:37:01 by ykhadiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0'
		&& s2[i] != '\0')
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	my_mlx_pixel_put(t_fractol *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.addr + (y * data->img.line_length
			+ x * (data->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

double	ft_map(int in, double in_end, double out_start, double out_end)
{
	double	mapped_val;

	mapped_val = out_start + ((out_end - out_start) / in_end) * in;
	return (mapped_val);
}

void	set_mapped_values(t_fractol *data)
{	
	data->a = ft_map(data->x, WIDTH, data->re_oregin - data->zoom,
			data->re_oregin + data->zoom);
	data->b = ft_map(data->y, HEIGHT, data->im_oregin - data->zoom,
			data->im_oregin + data->zoom);
	if (!data->julia)
	{
		data->c_r = data->a;
		data->c_i = data->b;
	}
}

int	win_destroy(void *data)
{
	(void)data;
	free(data);
	exit(0);
}
