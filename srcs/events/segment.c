/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imback <imback@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:27:50 by imback            #+#    #+#             */
/*   Updated: 2024/08/25 17:12:44 by imback           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


static int	interpolate_color(int color_start, int color_end, float t)
{
	int		r;
	int		g;
	int		b;

	r = (int)((1 - t) * ((color_start >> 16) & 0xFF)
			+ t * ((color_end >> 16) & 0xFF));
	g = (int)((1 - t) * ((color_start >> 8) & 0xFF)
			+ t * ((color_end >> 8) & 0xFF));
	b = (int)((1 - t) * (color_start & 0xFF) + t * (color_end & 0xFF));
	return ((r << 16) | (g << 8) | b);
}

static void	place_pixel(t_display *display, t_point p0)
{
	if (p0.x >= 0 && p0.x < WINDOW_WIDTH && p0.y >= 0 && p0.y < WINDOW_HEIGHT)
		img_pix_put(display->img, p0.x, p0.y, p0.color);

}

static void	place_point(t_display *display, t_point p0, t_point p1,
	t_segment *segment)
{
	int		e2;
	float	t;

	while (p0.x != p1.x || p0.y != p1.y)
	{
		if (segment->dx > segment->dy)
			t = (float)(p0.x - segment->start_x) / segment->dx;
		else
			t = (float)(p0.y - segment->start_y) / segment->dy;
		p0.color = interpolate_color(segment->start_color, segment->end_color,
				t);
		place_pixel(display, p0);
		e2 = 2 * segment->err;
		if (e2 > -segment->dy)
		{
			segment->err -= segment->dy;
			p0.x += segment->sx;
		}
		if (e2 < segment->dx)
		{
			segment->err += segment->dx;
			p0.y += segment->sy;
		}
	}
}

static void	get_data_segment(t_point p0, t_point p1, t_segment *segment)
{
	segment->dx = ft_abs(p1.x - p0.x);
	segment->dy = ft_abs(p1.y - p0.y);
	if (p0.x < p1.x)
		segment->sx = 1;
	else
		segment->sx = -1;
	if (p0.y < p1.y)
		segment->sy = 1;
	else
		segment->sy = -1;
	segment->err = segment->dx - segment->dy;
	segment->start_color = p0.color;
	segment->end_color = p1.color;
    segment->start_x = p0.x;
    segment->start_y = p0.y;
}

static void	draw_segment_between_points(t_point p0, t_point p1,
	t_display *display)
{
	t_segment	segment;

	get_data_segment(p0, p1, &segment);
	place_point(display, p0, p1, &segment);
}

void	draws_segments(t_point **points, t_display *display)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < display->matrix->rows)
	{
		x = 0;
		while (x < display->matrix->cols)
		{
			if (x + 1 < display->matrix->cols)
				draw_segment_between_points(points[y][x],
					points[y][x + 1], display);
			if (y + 1 < display->matrix->rows)
				draw_segment_between_points(points[y][x],
					points[y + 1][x], display);
			++x;
		}
		++y;
	}
}
