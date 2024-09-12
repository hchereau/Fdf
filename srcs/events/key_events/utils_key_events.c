/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_key_events.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:44:05 by hucherea          #+#    #+#             */
/*   Updated: 2024/09/12 14:23:01 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	y_translation_key(int keycode, t_display *display)
// {
// 	if (keycode == UP_KEY)
// 	{
// 		display->translation_y -= TRANSLATION;
// 	}
// 	else if (keycode == DOWN_KEY)
// 	{
// 		display->translation_y += TRANSLATION;
// 	}
// }

// void	x_translation_key(int keycode, t_display *display)
// {
// 	if (keycode == RIGHT_KEY)
// 	{
// 		display->translation_x += TRANSLATION;
// 	}
// 	else if (keycode == LEFT_KEY)
// 	{
// 		display->translation_x -= TRANSLATION;
// 	}
// }

void	x_translation_key(t_display *display)
{
	size_t	i;

	i = 0;
	while (i < TAB_KEY_SIZE)
	{
		if (display->keys[i].keycode == RIGHT_KEY
			&& display->keys[i].state == pressed)
		{
			display->translation_x += TRANSLATION;
		}
		if (display->keys[i].keycode == LEFT_KEY
			&& display->keys[i].state == pressed)
		{
			display->translation_x -= TRANSLATION;
		}
		++i;
	}
}

void	y_translation_key(t_display *display)
{
	size_t	i;

	i = 0;
	while (i < TAB_KEY_SIZE)
	{
		if (display->keys[i].keycode == UP_KEY
			&& display->keys[i].state == pressed)
		{
			display->translation_y -= TRANSLATION;
		}
		if (display->keys[i].keycode == DOWN_KEY
			&& display->keys[i].state == pressed)
		{
			display->translation_y += TRANSLATION;
		}
		++i;
	}
}
