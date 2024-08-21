/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imback <imback@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:53:48 by imback            #+#    #+#             */
/*   Updated: 2024/08/21 16:31:28 by imback           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	refocusing_matrice(t_display *display, float theta)
{
	size_t	offset_x;
	size_t	offset_y;
	size_t	x;
	size_t	y;

	offset_x = (WINDOW_WIDTH / 2.0) - ((display->matrix->cols - 1)
			* cos(theta) / 2.0);
	offset_y = (WINDOW_HEIGHT / 2.0) - ((display->matrix->rows - 1)
			* sin(theta) / 2.0);
	y = 0;
	while (y < display->matrix->rows)
	{
		x = 0;
		while (x < display->matrix->cols)
		{
			display->matrix->points[y][x].x += offset_x;
			display->matrix->points[y][x].y += offset_y;
			++x;
		}
		++y;
	}
}

void	isometric(t_display *display)
{
	size_t		x;
	size_t		y;
	size_t		x_point;
	size_t		y_point;
	const float	theta = M_PI / 6;


///wtf
	display->center = (t_center *)malloc(sizeof(t_center));
	center_points(display->center, display);

	y = 0;
	while (y < display->matrix->rows)
	{
		x = 0;
		while (x < display->matrix->cols)
		{
			x_point = display->matrix->points[y][x].x - display->center->x_center;
			y_point = display->matrix->points[y][x].y - display->center->y_center;
			display->matrix->points[y][x].x = (x_point - y_point) * cos(theta);
			display->matrix->points[y][x].y = (x_point + y_point) * sin(theta);
			++x;
		}
		++y;
	}
	refocusing_matrice(display, theta);
}