/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 09:13:01 by imback            #+#    #+#             */
/*   Updated: 2024/09/06 17:48:49 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	add_events(t_display *display)
{
	size_t		x;
	size_t		y;
	t_center	center_center;

	y = 0;
	center_points(&center_center, display);
	while (y < display->matrix->rows)
	{
		x = 0;
		while (x < display->matrix->cols)
		{
			add_zoom(display, &center_center, y, x);
			isometric(display, y, x);
			horizontal_rotate(display, y, x);
			vertical_rotate(display, y, x);
			++x;
		}
		++y;
	}
}

void	events(t_display *display)
{
	free_matrix(display->matrix);
	display->matrix->points = copy_points(display->matrix->cp_points,
			display->matrix->rows, display->matrix->cols);
	add_events(display);
	center(display);
	refresh_window(display);
}
