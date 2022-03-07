/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhadiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:24:12 by ykhadiri          #+#    #+#             */
/*   Updated: 2022/03/04 18:41:59 by ykhadiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 700
# define HEIGHT 700
# define BLK "\e[0;30m"
# define RED "\e[0;31m"
# define GRN "\e[0;32m"
# define YEL "\e[0;33m"
# define BLU "\e[0;34m"
# define MAG "\e[0;35m"
# define CYN "\e[0;36m"
# define WHT "\e[0;37m"

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	t_image	img;
	double	re_oregin;
	double	im_oregin;
	int		x;
	int		y;
	int		iteration;
	int		color;
	int		color_id;
	int		new_color;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	a;
	double	b;
	double	zoom;
	int		max_iteration;
	int		julia;
	int		julia_bool;
	int		burning_ship;
}	t_fractol;
void	fractols(void);
void	controls(void);
void	launch(t_fractol *data);
int		key_hook(int key, t_fractol *data);
double	ft_map(int in, double in_end, double out_start, double out_end);
void	my_mlx_pixel_put(t_fractol *data, int x, int y, int color);
void	set_mapped_values(t_fractol *data);
int		mouse_hook(int button, int x, int y, t_fractol *data);
void	ft_draw(t_fractol *data);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_moves_julia(t_fractol *data, int key);
int		win_destroy(void *data);
int		key_hook_val(int x, int y, t_fractol *data);
void	ft_calc(t_fractol *data);
void	init_vals(t_fractol *data);
void	change_color(t_fractol *data);
void	reset(t_fractol *data);
#endif
