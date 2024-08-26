/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imback <imback@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:08:21 by imback            #+#    #+#             */
/*   Updated: 2024/08/26 15:19:12 by imback           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	horizontal_rotate(t_display *display)
{
	size_t		x;
	size_t		y;
	float		x_temp;
	float		z_temp;
	const float	radius_angle = display->horizontal_angle * M_PI / 180;


	y = 0;
	printf("horizontal_angle: %f\n\n", display->horizontal_angle);
	while(y < display->matrix->rows)
	{
		x = 0;
		while(x < display->matrix->cols)
		{
			x_temp = display->matrix->points[y][x].x * cos(radius_angle) + display->matrix->points[y][x].z * sin(radius_angle);
			z_temp = -display->matrix->points[y][x].x * sin(radius_angle) + display->matrix->points[y][x].z * cos(radius_angle);
			display->matrix->points[y][x].z = x_temp;
			display->matrix->points[y][x].x = z_temp;
			++x;
		}
		++y;
	}
}