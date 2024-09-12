/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:06:47 by imback            #+#    #+#             */
/*   Updated: 2024/09/12 14:30:10 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	zoom_key(int keycode, t_display *display)
// {
// 	if (keycode == PLUS_KEY)
// 	{
// 		if (display->zoom == 0)
// 			display->zoom += 0.5;
// 		else
// 			display->zoom *= 2;
// 	}
// 	else if (keycode == MINUS_KEY && display->zoom > 0)
// 	{
// 		display->zoom /= 2;
// 	}
// }

// void	rotate_isometric_key(int keycode, t_display *display)
// {
// 	if (keycode == Q_KEY)
// 	{
// 		display->isometric_angle += ANGLE_ROTATE_ISOMETRIC;
// 	}
// 	else if (keycode == E_KEY)
// 	{
// 		display->isometric_angle -= ANGLE_ROTATE_ISOMETRIC;
// 	}
// }

// void	rotate_vertical_key(int keycode, t_display *display)
// {
// 	if (keycode == W_KEY)
// 	{
// 		display->vertical_angle -= ANGLE_ROTATE;
// 	}
// 	else if (keycode == S_KEY)
// 	{
// 		display->vertical_angle += ANGLE_ROTATE;
// 	}
// }

// void	rotate_horizontal_key(int keycode, t_display *display)
// {
// 	if (keycode == D_KEY)
// 	{
// 		display->horizontal_angle += ANGLE_ROTATE;
// 	}
// 	else if (keycode == A_KEY)
// 	{
// 		display->horizontal_angle -= ANGLE_ROTATE;
// 	}
// }

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

void	zoom_key(t_display *display)
{
	size_t	i;

	i = 0;
	printf("--------------------\n");
	while (i < TAB_KEY_SIZE)
	{
		printf("keycode: %d | pressed: %d\n", display->keys[i].keycode, display->keys[i].state);
		if (display->keys[i].keycode == PLUS_KEY
			&& display->keys[i].state == pressed)
		{
			if (display->zoom == 0)
				display->zoom += 0.5;
			else
				display->zoom *= 2;
		}
		if (display->keys[i].keycode == MINUS_KEY && display->zoom > 0
			&& display->keys[i].state == pressed)
		{
			display->zoom /= 2;
		}
		++i;
	}
}

void	key_events(int keycode, t_display *display)
{
	(void)keycode;
	zoom_key(display);
	rotate_horizontal_key(display);
	rotate_vertical_key(display);
	y_translation_key(display);
	x_translation_key(display);
}
