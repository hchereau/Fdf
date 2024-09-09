/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_zoom.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:24:00 by hucherea          #+#    #+#             */
/*   Updated: 2024/09/09 16:22:28 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

bool	is_good_zoom(t_display *display)
{
	size_t		x;
	size_t		y;

	y = 0;
	while (y < display->matrix->rows)
	{
		x = 0;
		while (x < display->matrix->cols)
		{
			if (display->matrix->points[y][x].x > WINDOW_WIDTH
				|| display->matrix->points[y][x].x < 0
				|| display->matrix->points[y][x].y > WINDOW_HEIGHT
				|| display->matrix->points[y][x].y < 0)
			{
				return (false);
			}
			++x;
		}
		++y;
	}
	return (true);
}


void	fix_zoom(t_display *display)
{
	static bool	zoomed = false;

	if (is_good_zoom(display) == true && zoomed == false)
	{
		display->zoom += 1;
		free_matrix(display->matrix);
		display->matrix->points = copy_points(display->matrix->cp_points,
				display->matrix->rows, display->matrix->cols);
		setup_points(display);
	}
	else if (zoomed == false)
	{
		zoomed = true;
		display->zoom *= 0.8;
		free_matrix(display->matrix);
		display->matrix->points = copy_points(display->matrix->cp_points,
				display->matrix->rows, display->matrix->cols);
		setup_points(display);
	}
	if (is_good_zoom(display) == false)
	{
		zoomed = false;
		display->zoom -= 0.5;
		setup_points(display);
	}
}
