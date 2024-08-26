/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imback <imback@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:21:33 by imback            #+#    #+#             */
/*   Updated: 2024/08/26 15:30:04 by imback           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	add_zoom(t_display *display)
{
	size_t		x;
	size_t		y;
	t_center	center_zoom;

	y = 0;
	printf("add_zoom\n");
	center_points(&center_zoom, display);
	printf("\n\n");
	while (y < display->matrix->rows)
	{
		x = 0;
		while (x < display->matrix->cols)
		{
			center_zoom.x_offset = display->matrix->points[y][x].x
				- WINDOW_WIDTH / 2;
			center_zoom.y_offset = display->matrix->points[y][x].y
				- WINDOW_HEIGHT / 2;
			display->matrix->points[y][x].x += (center_zoom.x_offset
					* display->zoom) + center_zoom.x_center;
			display->matrix->points[y][x].y += (center_zoom.y_offset
					* display->zoom) + center_zoom.y_center;
			printf("zoom: %f\n", display->zoom);
			if (display->zoom == 1)
				display->matrix->points[y][x].z *= display->zoom * 2;
			else if (display->zoom != 0)
				display->matrix->points[y][x].z *= display->zoom;
			++x;
		}
		++y;
	}

}
