/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imback <imback@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:06:47 by imback            #+#    #+#             */
/*   Updated: 2024/08/26 18:31:10 by imback           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	zoom_key(int keycode, t_display *display)
{
	if (keycode == PLUS_KEY)
	{
		display->zoom += ZOOM;
	}
	else if (keycode == MINUS_KEY && display->zoom > 0)
	{
		display->zoom -= ZOOM;
	}
}

static void	rotate_vertical_key(int keycode, t_display *display)
{
	if (keycode == W_KEY)
	{
		display->vertical_angle += ANGLE_ROTATE;
	}
	else if (keycode == S_KEY)
	{
		display->vertical_angle -= ANGLE_ROTATE;
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

static void	key_events(int keycode, t_display *display)
{
	zoom_key(keycode, display);
	rotate_horizontal_key(keycode, display);
	rotate_vertical_key(keycode, display);
}

int	key_hook(int keycode, t_display *display)
{
	printf("keycode: %d\n", keycode);
	if (keycode == ESC_KEY)
	{
		close_window(display);
	}
	key_events(keycode, display);
	events(display);
	return (success);
}
