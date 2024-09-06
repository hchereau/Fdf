/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:53:48 by imback            #+#    #+#             */
/*   Updated: 2024/09/06 17:00:08 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(t_display *display, size_t y, size_t x)
{
	float		z_point;
	int			x_point;
	int			y_point;

	x_point = display->matrix->points[y][x].x;
	y_point = display->matrix->points[y][x].y;
	z_point = display->matrix->points[y][x].z;
	display->matrix->points[y][x].x = (x_point - y_point)
		* cos(display->isometric_angle);
	display->matrix->points[y][x].y = (x_point + y_point)
		* sin(display->isometric_angle) - z_point;
}
// void	isometric(t_display *display)
// {
// 	size_t		x;
// 	size_t		y;
// 	float		z_point;
// 	int			x_point;
// 	int			y_point;

// 	y = 0;
// 	while (y < display->matrix->rows)
// 	{
// 		x = 0;
// 		while (x < display->matrix->cols)
// 		{
// 			x_point = display->matrix->points[y][x].x;
// 			y_point = display->matrix->points[y][x].y;
// 			z_point = display->matrix->points[y][x].z;
// 			display->matrix->points[y][x].x = (x_point - y_point)
// 				* cos(display->isometric_angle);
// 			display->matrix->points[y][x].y = (x_point + y_point)
// 				* sin(display->isometric_angle) - z_point;
// 			++x;
// 		}
// 		++y;
// 	}
// }
