/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhadiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:28:52 by ykhadiri          #+#    #+#             */
/*   Updated: 2022/03/04 18:42:54 by ykhadiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_execute(t_fractol *data, char *str)
{
	data->burning_ship = 0;
	if (!ft_strcmp(str, "1"))
		data->julia = 0;
	else if (!ft_strcmp(str, "2"))
		data->julia = 1;
	else if (!ft_strcmp(str, "3"))
		data->burning_ship = 1;
	else
	{
		fractols();
		free(data);
		exit(1);
	}
	controls();
	launch(data);
}

int	main(int argc, char **argv)
{
	t_fractol	*data;

	data = malloc(sizeof(t_fractol));
	if (!data)
		return (0);
	if (argc != 2)
		fractols();
	else if (argc == 2)
	{
		ft_execute(data, argv[1]);
	}
	free(data);
	return (0);
}
