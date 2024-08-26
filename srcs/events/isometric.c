/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imback <imback@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:53:48 by imback            #+#    #+#             */
/*   Updated: 2024/08/26 15:26:04 by imback           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(t_display *display)
{
	size_t		x;
	size_t		y;
	float		z_point;
	int			x_point;
	int			y_point;
	const float	theta = M_PI / 6;

	y = 0;
	while (y < display->matrix->rows)
	{
		x = 0;
		while (x < display->matrix->cols)
		{
			x_point = display->matrix->points[y][x].x;
			y_point = display->matrix->points[y][x].y;
			z_point = display->matrix->points[y][x].z;
			display->matrix->points[y][x].x = (x_point - y_point) * cos(theta);
			display->matrix->points[y][x].y = (x_point + y_point) * sin(theta)
				- z_point;
			++x;
		}
		++y;
	}
}
