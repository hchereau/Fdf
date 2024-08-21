/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imback <imback@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:06:47 by imback            #+#    #+#             */
/*   Updated: 2024/08/21 11:26:48 by imback           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	zoom_key(int keycode, t_display *display)
{
	if (keycode == PLUS_KEY)
	{
		display->zoom += ZOOM;
	}
	if (keycode == MINUS_KEY && display->zoom > 0)
	{
		display->zoom -= ZOOM;
	}
}

static void	key_events(int keycode, t_display *display)
{
	zoom_key(keycode, display);
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
