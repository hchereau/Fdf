/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:08:21 by imback            #+#    #+#             */
/*   Updated: 2024/09/14 18:33:27 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	vertical_rotate(t_display *display, size_t y, size_t x)
{
	float		y_temp;
	float		z_temp;
	const float	radius_angle = (display->vertical_angle * M_PI / 180)
		* display->factor;

	y_temp = display->matrix->points[y][x].y * cos(radius_angle)
		- display->matrix->points[y][x].z * sin(radius_angle);
	z_temp = display->matrix->points[y][x].y * sin(radius_angle)
		+ display->matrix->points[y][x].z * cos(radius_angle);
	display->matrix->points[y][x].y = y_temp;
	display->matrix->points[y][x].z = z_temp;
}

void	horizontal_rotate(t_display *display, size_t y, size_t x)
{
	float		x_temp;
	float		z_temp;
	const float	radius_angle = (display->horizontal_angle * M_PI / 180)
		* display->factor;

	x_temp = display->matrix->points[y][x].x * cos(radius_angle)
		+ display->matrix->points[y][x].z * sin(radius_angle);
	z_temp = -display->matrix->points[y][x].x * sin(radius_angle)
		+ display->matrix->points[y][x].z * cos(radius_angle);
	display->matrix->points[y][x].z = x_temp;
	display->matrix->points[y][x].x = z_temp;
}

void	z_rotate(t_display *display, size_t y, size_t x)
{
	float		x_temp;
	float		y_temp;
	const float	radius_angle = display->z_rotate_angle * M_PI / 180;

	x_temp = display->matrix->points[y][x].x * cos(radius_angle)
		- display->matrix->points[y][x].y * sin(radius_angle);
	y_temp = display->matrix->points[y][x].x * sin(radius_angle)
		+ display->matrix->points[y][x].y * cos(radius_angle);
	display->matrix->points[y][x].x = x_temp;
	display->matrix->points[y][x].y = y_temp;
}
