/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imback <imback@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:53:48 by imback            #+#    #+#             */
/*   Updated: 2024/08/25 17:15:40 by imback           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(t_display *display)
{
	size_t		x;
	size_t		y;
	// float		z_point;
	int			x_point;
	int			y_point;
	const float	theta = M_PI / 6;

///wtf
	printf("isometric\n");
	display->center = (t_center *)malloc(sizeof(t_center));
	center_points(display->center, display);
	printf("\n\n");

	y = 0;
	while (y < display->matrix->rows)
	{
		x = 0;
		while (x < display->matrix->cols)
		{
			x_point = display->matrix->points[y][x].x;
			y_point = display->matrix->points[y][x].y;
			// z_point = display->matrix->points[y][x].z;


			display->matrix->points[y][x].x = (x_point - y_point) * cos(theta);
			display->matrix->points[y][x].y = (x_point + y_point) * sin(theta);
			++x;
		}
		++y;
	}
	free(display->center);
}