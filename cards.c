/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   card.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhadiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:37:05 by ykhadiri          #+#    #+#             */
/*   Updated: 2022/03/04 18:40:57 by ykhadiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractols(void)
{
	write(1, WHT"~~~~~~~~~~~~~~~ FRACT'OLS ~~~~~~~~~~~~~~~~~~\n", 53);
	write(1, YEL"||                                        ||\n", 53);
	write(1, YEL"||     1- Mandelbrot                      ||\n", 53);
	write(1, YEL"||     2- Julia                           ||\n", 53);
	write(1, YEL"||     3- Burning Ship                    ||\n", 53);
	write(1, YEL"||                                        ||\n", 53);
	write(1, WHT"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", 53);
}

void	controls(void)
{
	write(1, RED"~~~~~~~~~~~~~~~~~ CONTROLS ~~~~~~~~~~~~~~~~~\n", 53);
	write(1, GRN"||                                        ||\n", 53);
	write(1, GRN" ||   ↑           : Move Up              ||\n", 54);
	write(1, GRN" ||   →           : Move Right           ||\n", 54);
	write(1, GRN" ||   ↓           : Move Down            ||\n", 54);
	write(1, GRN" ||   ←           : Move Left            ||\n", 54);
	write(1, GRN" ||   +, P        : Increase Iteration   ||\n", 52);
	write(1, GRN" ||   -, N        : Decrease Iteration   ||\n", 52);
	write(1, GRN" ||   Scroll UP   : Zoom_In              ||\n", 52);
	write(1, GRN" ||   Scroll Down : Zoom_Out             ||\n", 52);
	write(1, GRN" ||   Left Click  : Stop Julia_Set       ||\n", 52);
	write(1, GRN" ||   C           : Change Color         ||\n", 52);
	write(1, GRN" ||   R           : Reset                ||\n", 54);
	write(1, GRN" ||   X, ESC, Q   : QUIT                 ||\n", 52);
	write(1, GRN"||                                        ||\n", 53);
	write(1, RED"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", 53);
}
