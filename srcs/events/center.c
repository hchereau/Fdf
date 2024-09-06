/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:39:54 by imback            #+#    #+#             */
/*   Updated: 2024/09/06 16:08:53 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	center_points(t_center *center, t_display *display)
{
	const size_t	nb_line = display->matrix->rows;
	const size_t	nb_cols = display->matrix->cols;

	center->x_max = display->matrix->points[nb_line - 1][nb_cols - 1].x;
	center->x_min = display->matrix->points[0][0].x;
	center->y_max = display->matrix->points[nb_line - 1][nb_cols - 1].y;
	center->y_min = display->matrix->points[0][0].y;
	center->x_center = (center->x_max + center->x_min) / 2;
	center->y_center = (center->y_max + center->y_min) / 2;
	center->x_offset = WINDOW_WIDTH / 2 - center->x_center;
	center->y_offset = WINDOW_HEIGHT / 2 - center->y_center;
}

void	center(t_display *display)
{
	size_t		x;
	size_t		y;
	t_center	center;

	center_points(&center, display);
	display->center = &center;
	y = 0;
	while (y < display->matrix->rows)
	{
		x = 0;
		while (x < display->matrix->cols)
		{
			display->matrix->points[y][x].x += center.x_offset;
			display->matrix->points[y][x].y += center.y_offset;
			++x;
		}
		++y;
	}
}
