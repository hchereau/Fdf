/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_key_events.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:44:05 by hucherea          #+#    #+#             */
/*   Updated: 2024/09/16 15:12:00 by hucherea         ###   ########.fr       */
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

void	z_power_key(t_display *display)
{
	size_t	i;

	i = 0;
	while (i < TAB_KEY_SIZE)
	{
		if (display->keys[i].keycode == SPACE_KEY
			&& display->keys[i].state == pressed)
		{
			display->z_power += Z_POWER;
		}
		if (display->keys[i].keycode == C_KEY
			&& display->keys[i].state == pressed)
		{
			display->z_power -= Z_POWER;
		}
		++i;
	}
}

void	vue_events(t_display *display)
{
	size_t	i;

	i = 0;
	while (i < TAB_KEY_SIZE)
	{
		if (display->keys[i].keycode == I_KEY
			&& display->keys[i].state == pressed)
		{
			setup_values_isometric(display);
			display->is_isometric = true;
		}
		else if (display->keys[i].keycode == P_KEY
			&& display->keys[i].state == pressed)
		{
			display->is_perspective = true;
			display->is_isometric = false;
		}
		else if (display->keys[i].keycode == N_KEY
			&& display->keys[i].state == pressed)
		{
			display->is_perspective = false;
			display->is_isometric = false;
		}
		++i;
	}
}
