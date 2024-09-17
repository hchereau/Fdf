/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:06:47 by imback            #+#    #+#             */
/*   Updated: 2024/09/17 10:17:00 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_horizontal_key(t_display *display)
{
	size_t	i;

	i = 0;
	while (i < TAB_KEY_SIZE)
	{
		if (display->keys[i].keycode == D_KEY
			&& display->keys[i].state == pressed)
		{
			display->horizontal_angle += ANGLE_ROTATE;
		}
		if (display->keys[i].keycode == A_KEY
			&& display->keys[i].state == pressed)
		{
			display->horizontal_angle -= ANGLE_ROTATE;
		}
		++i;
	}
}

void	rotate_vertical_key(t_display *display)
{
	size_t	i;

	i = 0;
	while (i < TAB_KEY_SIZE)
	{
		if (display->keys[i].keycode == W_KEY
			&& display->keys[i].state == pressed)
		{
			display->vertical_angle -= ANGLE_ROTATE;
		}
		if (display->keys[i].keycode == S_KEY
			&& display->keys[i].state == pressed)
		{
			display->vertical_angle += ANGLE_ROTATE;
		}
		++i;
	}
}

void	rotate_z_key(t_display *display)
{
	size_t	i;

	i = 0;
	while (i < TAB_KEY_SIZE)
	{
		if (display->keys[i].keycode == E_KEY
			&& display->keys[i].state == pressed)
		{
			display->z_rotate_angle += ANGLE_ROTATE;
		}
		if (display->keys[i].keycode == Q_KEY
			&& display->keys[i].state == pressed)
		{
			display->z_rotate_angle -= ANGLE_ROTATE;
		}
		++i;
	}
}

void	zoom_key(t_display *display)
{
	size_t	i;

	i = 0;
	while (i < TAB_KEY_SIZE)
	{
		if (display->keys[i].keycode == PLUS_KEY
			&& display->keys[i].state == pressed)
		{
			if (display->zoom == 0)
				display->zoom += 0.01;
			else
				display->zoom *= 1.01;
		}
		if (display->keys[i].keycode == MINUS_KEY && display->zoom > 0
			&& display->keys[i].state == pressed)
		{
			display->zoom /= 1.01;
		}
		++i;
	}
}

void	key_events(t_display *display)
{
	if (display->keys[12].state == pressed)
	{
		close_window(display);
	}
	zoom_key(display);
	rotate_horizontal_key(display);
	rotate_vertical_key(display);
	y_translation_key(display);
	x_translation_key(display);
	rotate_z_key(display);
	z_power_key(display);
	vue_events(display);
}
