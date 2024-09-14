/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:27:32 by hucherea          #+#    #+#             */
/*   Updated: 2024/09/13 15:39:55 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



int	key_press(int keycode, t_display *display)
{
	size_t	i;

	i = 0;
	while (i < TAB_KEY_SIZE)
	{
		if (display->keys[i].keycode == keycode)
		{
			display->keys[i].state = pressed;
		}
		i++;
	}
	return (0);
}

int	key_release(int keycode, t_display *display)
{
	size_t	i;

	i = 0;
	while (i < TAB_KEY_SIZE)
	{
		if (display->keys[i].keycode == keycode)
		{
			display->keys[i].state = not_pressed;
		}
		i++;
	}
	return (0);
}

// int	key_press(int keycode, t_display *display)
// {
// 	size_t	i;

// 	i = 0;
// 	if (keycode == ESC_KEY)
// 	{
// 		close_window(display);
// 	}
// 	else
// 	{
// 		while (i < TAB_KEY_SIZE)
// 		{
// 			if (display->keys[i].keycode == keycode)
// 			{
// 				display->keys[i].f(keycode, display);
// 			}
// 			i++;
// 		}
// 	}
// 	return (0);
// }
