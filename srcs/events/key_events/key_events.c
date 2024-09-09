/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:06:47 by imback            #+#    #+#             */
/*   Updated: 2024/09/09 15:06:01 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	zoom_key(int keycode, t_display *display)
{
	if (keycode == PLUS_KEY)
	{
		if (display->zoom == 0)
			display->zoom += 0.5;
		else
			display->zoom *= 2;
	}
	else if (keycode == MINUS_KEY && display->zoom > 0)
	{
		display->zoom /= 2;
	}
}

static void	rotate_isometric_key(int keycode, t_display *display)
{
	if (keycode == Q_KEY)
	{
		display->isometric_angle += ANGLE_ROTATE_ISOMETRIC;
	}
	else if (keycode == E_KEY)
	{
		display->isometric_angle -= ANGLE_ROTATE_ISOMETRIC;
	}
}

static void	rotate_vertical_key(int keycode, t_display *display)
{
	if (keycode == W_KEY)
	{
		display->vertical_angle -= ANGLE_ROTATE;
	}
	else if (keycode == S_KEY)
	{
		display->vertical_angle += ANGLE_ROTATE;
	}
}

static void	rotate_horizontal_key(int keycode, t_display *display)
{
	if (keycode == D_KEY)
	{
		display->horizontal_angle += ANGLE_ROTATE;
	}
	else if (keycode == A_KEY)
	{
		display->horizontal_angle -= ANGLE_ROTATE;
	}
}

void	key_events(int keycode, t_display *display)
{
	zoom_key(keycode, display);
	rotate_isometric_key(keycode, display);
	rotate_horizontal_key(keycode, display);
	rotate_vertical_key(keycode, display);
	y_translation_key(keycode, display);
	x_translation_key(keycode, display);
}
