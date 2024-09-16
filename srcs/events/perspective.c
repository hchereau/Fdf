/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:37:40 by hucherea          #+#    #+#             */
/*   Updated: 2024/09/16 15:11:24 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	perspective(t_display *display, size_t y, size_t x)
{
	double	perspective;

	if (display->camera != 0)
	{
		perspective = FOCAL_LENGTH;
		perspective /= DIST_CAM;
		display->matrix->points[y][x].x = display->matrix->points[y][x].x
			* perspective + WINDOW_WIDTH / 2;
		display->matrix->points[y][x].y = display->matrix->points[y][x].y
			* perspective + WINDOW_HEIGHT / 2;
	}
}
