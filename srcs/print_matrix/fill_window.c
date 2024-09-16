/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:32:16 by imback            #+#    #+#             */
/*   Updated: 2024/09/16 14:32:17 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	setup_loop_mlx(t_display *display)
{
	gettimeofday(&display->last_time, NULL);
	display->fps = 0.0;
	display->frame_count = 0;
	mlx_hook(display->p_win, KeyPress, KeyPressMask, key_press, display);
	mlx_hook(display->p_win, KeyRelease, KeyReleaseMask, key_release, display);
	mlx_hook(display->p_win, 17, 0, close_window, display);
	mlx_loop_hook(display->p_mlx, key_hook, display);
	mlx_loop(display->p_mlx);
}

void	fill_window(t_display *display)
{
	fill_image(display->matrix->points, display);
	mlx_put_image_to_window(display->p_mlx, display->p_win,
		display->img->img, 0, 0);
	setup_loop_mlx(display);
}
