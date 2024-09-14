/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_key_events.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:44:05 by hucherea          #+#    #+#             */
/*   Updated: 2024/09/13 15:41:31 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
