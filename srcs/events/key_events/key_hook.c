/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:49:00 by imback            #+#    #+#             */
/*   Updated: 2024/09/09 15:01:48 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, t_display *display)
{
	if (keycode == ESC_KEY)
	{
		close_window(display);
	}
	key_events(keycode, display);
	events(display);
	return (success);
}
