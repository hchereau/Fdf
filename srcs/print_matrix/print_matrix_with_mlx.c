/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix_with_mlx.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:45:57 by imback            #+#    #+#             */
/*   Updated: 2024/09/16 15:12:24 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_image(t_point **points, t_display *display)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < display->matrix->rows)
	{
		x = 0;
		while (x < display->matrix->cols)
		{
			if (points[y][x].x <= WINDOW_WIDTH && points[y][x].x >= 0
				&& points[y][x].y <= WINDOW_HEIGHT && points[y][x].y >= 0)
				img_pix_put(display->img, points[y][x].x, points[y][x].y,
					points[y][x].color);
			++x;
		}
		++y;
	}
	draws_segments(display->matrix->points, display);
}

void	setup_points(t_display *display)
{
	size_t		x;
	size_t		y;
	t_center	center_zoom;

	y = 0;
	center_points(&center_zoom, display);
	while (y < display->matrix->rows)
	{
		x = 0;
		while (x < display->matrix->cols)
		{
			add_zoom(display, &center_zoom, y, x);
			display->matrix->points[y][x].z *= 0.5;
			isometric(display, y, x);
			++x;
		}
		++y;
	}
	center(display);
	fix_zoom(display);
}

void	print_matrix_with_mlx(t_display *display)
{
	setup_mlx(display);
	display->matrix->cp_points = copy_points(display->matrix->points,
			display->matrix->rows,
			display->matrix->cols);
	setup_points(display);
	fill_window(display);
}
