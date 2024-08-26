/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imback <imback@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:56:21 by imback            #+#    #+#             */
/*   Updated: 2024/08/26 15:36:27 by imback           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	setup_display(t_display *display)
{
	display->p_mlx = mlx_init();
	display->p_win = mlx_new_window(display->p_mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT, "fdf");
}

static void	setup_img(t_display *display)
{
	display->img = malloc(sizeof(t_img));
	display->img->img = mlx_new_image(display->p_mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	display->img->addr = mlx_get_data_addr(display->img->img,
			&display->img->bpp,
			&display->img->line_len, &display->img->endian);
}

static void	setup_values(t_display *display)
{
	display->zoom = ZOOM;
	display->horizontal_angle = ANGLE_ROTATE_HORIZONTAL;
}

void	setup_mlx(t_display *display)
{
	setup_display(display);
	setup_img(display);
	setup_values(display);
}
