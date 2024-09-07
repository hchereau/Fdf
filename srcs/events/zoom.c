/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:21:33 by imback            #+#    #+#             */
/*   Updated: 2024/09/07 11:19:49 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	get_offset(t_center *center_zoom, t_point *point)
{
	center_zoom->x_offset = point->x - WINDOW_WIDTH / 2;
	center_zoom->y_offset = point->y - WINDOW_HEIGHT / 2;
}

void	add_zoom(t_display *display, t_center *center_zoom, size_t y, size_t x)
{
	get_offset(center_zoom, &display->matrix->points[y][x]);
	display->matrix->points[y][x].x += (center_zoom->x_offset
			* display->zoom) + center_zoom->x_center;
	display->matrix->points[y][x].y += (center_zoom->y_offset
			* display->zoom) + center_zoom->y_center;
	display->matrix->points[y][x].z *= display->zoom;
}
