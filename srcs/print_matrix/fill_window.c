/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:32:16 by imback            #+#    #+#             */
/*   Updated: 2024/09/06 16:18:13 by hucherea         ###   ########.fr       */
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

void	fill_window(t_display *display)
{
	isometric(display);
	center(display);
	fill_image(display->matrix->points, display);
	mlx_put_image_to_window(display->p_mlx, display->p_win,
		display->img->img, 0, 0);
	mlx_key_hook(display->p_win, key_hook, display);
	mlx_loop(display->p_mlx);
}
