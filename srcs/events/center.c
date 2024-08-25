/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imback <imback@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:39:54 by imback            #+#    #+#             */
/*   Updated: 2024/08/25 22:45:26 by imback           ###   ########.fr       */
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


	printf("x_max: %f\n x_min: %f\n", center->x_max, center->x_min);
	printf("rows: %ld\n cols: %ld\n", nb_line, nb_cols);
	printf("x_center: %f\n y_center: %f\n", center->x_center, center->y_center);
	printf("x_offset: %f\n y_offset: %f\n", center->x_offset, center->y_offset);
}


void	center(t_display *display)
{
	size_t		x;
	size_t		y;
	t_center	center;

	printf("center\n");
	center_points(&center, display);
	display->center = &center;
	printf("\n\n");
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