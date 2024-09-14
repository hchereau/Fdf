/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 09:13:01 by imback            #+#    #+#             */
/*   Updated: 2024/09/14 15:42:28 by hucherea         ###   ########.fr       */
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
	center(display);
}

void	add_translations(t_display *display)
{
	size_t		x;
	size_t		y;

	y = 0;
	while (y < display->matrix->rows)
	{
		x = 0;
		while (x < display->matrix->cols)
		{
			x_translation(display, y, x);
			y_translation(display, y, x);
			++x;
		}
		++y;
	}
}

static void	update_fps(t_display *display)
{
    struct timeval	current_time;
    long			seconds;
    long			microseconds;
    float			elapsed_time;

    gettimeofday(&current_time, NULL);
    seconds = current_time.tv_sec - display->last_time.tv_sec;
    microseconds = current_time.tv_usec - display->last_time.tv_usec;
    elapsed_time = seconds + microseconds * 1e-6;
    display->frame_count++;
    if (elapsed_time > 1.0)
    {
        display->fps = display->frame_count / elapsed_time;
        display->frame_count = 0;
        display->last_time = current_time;
    }
}

static void	display_fps(t_display *display)
{
	char	fps_str[32];

	snprintf(fps_str, sizeof(fps_str), "FPS: %.2f", display->fps);
	mlx_string_put(display->p_mlx, display->p_win, 10, 10, 0xFFFFFF, fps_str);
}

void	events(t_display *display)
{
	free_matrix(display->matrix);
	display->matrix->points = copy_points(display->matrix->cp_points,
			display->matrix->rows, display->matrix->cols);
	add_events(display);
	add_translations(display);
	refresh_window(display);
	update_fps(display);
	display_fps(display);
}
