/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:53:48 by imback            #+#    #+#             */
/*   Updated: 2024/09/14 16:55:54 by hucherea         ###   ########.fr       */
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
		* cos(M_PI / 6);
	display->matrix->points[y][x].y = (x_point + y_point)
		* sin(M_PI / 6) - z_point;
}
